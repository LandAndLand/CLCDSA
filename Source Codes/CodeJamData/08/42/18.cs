using System;
using System.Collections.Generic;
using System.IO;

public class Numbers
{
    static Int64 x1, x2, x3, y1, y2, y3;

    static Int64 Calc()
    {
        return Math.Abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
    }

    [STAThread]
    public static void Main(string[] args)
    {
        x1 = 1;
        y1 = 1;
        x2 = 2;
        y2 = 3;
        x3 = 5;
        y3 = 8;
        double dd = Calc();
        //StreamReader sr = new StreamReader(args[0]);
        //StreamWriter sw = new StreamWriter(args[1]);
        StreamReader sr = new StreamReader("input.txt");
        StreamWriter sw = new StreamWriter("output.txt");

        Int64 m_nCase = Convert.ToInt64(sr.ReadLine());
        String[] tmpA;
        for (Int64 cs = 1; cs <= m_nCase; cs++)
        {
            tmpA = sr.ReadLine().Split(' ');
            Int64 m_N = Convert.ToInt64(tmpA[0]);
            Int64 m_M = Convert.ToInt64(tmpA[1]);
            Int64 m_A = Convert.ToInt64(tmpA[2]);
            x1 = 0;
            y1 = 0;
            bool bF = false;

            for (int i = 0; i <= m_N; i++)
                for (int j = 0; j <= m_M; j++)
                    if (!bF &&(i != x1 || j != y1))
                    {
                        x2 = i;
                        y2 = j;
                        for (int ii = 0; ii <= m_N; ii++)
                            for (int jj = 0; jj <= m_M; jj++)
                                if (!bF && (ii != x1 || jj != y1) && (ii != x2 || jj != y2))
                                {
                                    x3 = ii;
                                    y3 = jj;
                                    if(Calc()==m_A)
                                    {
                                        bF = true;
                                        break;
                                    }
                                }
                    }

            if (bF) sw.Write(String.Format("Case #{0:G}: {1:G} {2:G} {3:G} {4:G} {5:G} {6:G}\n", cs, x1, y1, x2, y2, x3, y3));
                else sw.Write(String.Format("Case #{0:G}: IMPOSSIBLE\n", cs)); 
        }
        sr.Close();
        sw.Close();
    }
}