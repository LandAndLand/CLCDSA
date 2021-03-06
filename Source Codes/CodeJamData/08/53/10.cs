using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    public static Int64[,] memoiz;
    public static Int64 m_M;
    public static Int64 m_N;
    public static bool[,] m_aP;
    public static bool[,] m_aR;
    public static int[] m_T={1,2,4,8,16,32,64,128,256,512,1024};
    public static Int64 FindProc(int m_I, int m_J, int m_S)
    {
        if (m_I >= m_M) return 0;
        if (m_J >= m_N) return FindProc(m_I+1, 0, m_S);
        if (m_J == 0 && memoiz[m_I, m_S] != 0) return memoiz[m_I, m_S];
        Int64 m_SS = m_S;
        if (m_J == 0) m_S = 0;
        Int64 max = 0;

        Int64 t1 = 0, t2 = 0;
        if ( m_aP[m_I, m_J] &&
            (m_J==0 || !m_aR[m_I, m_J-1])&&
            (m_J==m_N-1 || !m_aR[m_I, m_J+1])&&
            (m_J==0 || m_I==0 || !m_aR[m_I-1, m_J-1])&&
            (m_J==m_N-1 || m_I==0 || !m_aR[m_I-1, m_J+1]))
        {
            m_aR[m_I, m_J] = true;
            t1 = FindProc(m_I, m_J + 1, m_S + m_T[m_J]) + 1;
            m_aR[m_I, m_J] = false;
        }
        t2 = FindProc(m_I, m_J + 1, m_S);

        max = Math.Max(t1, t2);

        if (m_J == 0) memoiz[m_I, m_SS] = max;
        return max;
    }

    [STAThread]
    public static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        String[] tmpA;
        String tmp;
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            memoiz = new long[10, 3000];
            tmpA = sr.ReadLine().Split(' ');
            m_M = Convert.ToInt64(tmpA[0]);
            m_N = Convert.ToInt64(tmpA[1]);
            m_aP = new bool[m_M+1, m_N+1];
            m_aR = new bool[m_M+1, m_N+1];

            for (int i = 0; i < m_M; i++)
            {
                tmp = sr.ReadLine();
                for (int j = 0; j < m_N; j++)
                    if (tmp[j] == '.') m_aP[i, j] = true;
                    else m_aP[i, j] = false;
            }

            Int64 ans = FindProc(0,0,0);

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, ans));
        }
        sr.Close();
        sw.Close();
    }
}