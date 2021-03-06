using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    [STAThread]
    public static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        String[] tmpA;
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            tmpA = sr.ReadLine().Split(' ');
            Int64 m_H = Convert.ToInt64(tmpA[0]);
            Int64 m_W = Convert.ToInt64(tmpA[1]);
            Int64 m_R = Convert.ToInt64(tmpA[2]);
            bool[,] m_aP = new bool[m_H + 20, m_W + 20];
            Int64[,] m_aRez = new Int64[m_H + 20, m_W + 20];

            Int64 r = 0;
            Int64 c = 0;
            for (int i = 0; i < m_R; i++)
            {
                tmpA = sr.ReadLine().Split(' ');
                m_aP[Convert.ToInt64(tmpA[0]), Convert.ToInt64(tmpA[1])] = true;
            }

            m_aRez[1, 1] = 1;
            for (int i = 1; i <= m_H; i++)
                for (int j = 1; j <= m_W; j++)
                    if (m_aRez[i, j] != 0 && !m_aP[i,j])
                    {
                        m_aRez[i + 1, j + 2] = (m_aRez[i + 1, j + 2] + m_aRez[i, j]) % 10007;
                        m_aRez[i + 2, j + 1] = (m_aRez[i + 2, j + 1] + m_aRez[i, j]) % 10007;
                    }
            sw.Write(String.Format("Case #{0:G}: {1:G}\n", cs, m_aRez[m_H, m_W]));
        }
        sr.Close();
        sw.Close();
    }
}