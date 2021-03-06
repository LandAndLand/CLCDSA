using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    private static String m_S;
    private static int[] m_SA;
    private static int[] m_SAtem;
    private static int m_K;
    private static bool[] kAU;
    private static int[] kA;
    static int min;
    private static int lenK;
    public static int ApplyPer()
    {
        for (int i = 0; i < lenK; i++)
            for (int j = 0; j < m_K; j++)
                m_SAtem[i * m_K + j] = m_SA[i * m_K + kA[j]];

        int ret = 1;
        for (int i = 1; i < m_SAtem.Length; i++)
            if (m_SAtem[i] != m_SAtem[i - 1]) ret++;

        return ret;
    }
    public static void GenK(int ind)
    {
        if (ind==m_K)
        {
            min = Math.Min(min, ApplyPer());
            return;
        }

        for (int i = 0; i < m_K; i++)
            if(!kAU[i])
            {
                kAU[i] = true;
                kA[ind] = i;
                GenK(ind+1);
                kAU[i] = false;
            }
    }

    [STAThread]
    public static void Main(string[] args)
    {
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            m_K = Convert.ToInt32(sr.ReadLine());
            m_S = sr.ReadLine();
            m_SA = new int[m_S.Length];
            m_SAtem = new int[m_S.Length];
            for (int i = 0; i < m_S.Length; i++)
                m_SA[i] = m_S[i];

            kAU = new bool[m_K];
            kA = new int[m_K];
            for (int i = 0; i < m_K; i++)
                kAU[i] = false;
            min = 10000000;
            lenK = m_S.Length / m_K;
            GenK(0);

            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, min));
        }
        sr.Close();
        sw.Close();
    }
}