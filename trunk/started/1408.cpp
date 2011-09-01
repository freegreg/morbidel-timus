/*
 *  ACM Timus Online
 *  Polynomial Multiplication
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

#define ABS(x)			((x) > 0 ? (x) : -(x))
#define FILE_INPUT		"input.txt"


void SplitTokenString(vector<string> &vOut, string sSource, string sDelim)
{
	int i;
	string cuv = string("");

	for (i = 0; i < sSource.size(); i++)
	{
		int nPos = (int) sDelim.find(sSource[i]);
		if (nPos >= 0)
		{
			if (cuv.size() > 0)
			{
				vOut.push_back(cuv);
				cuv = string("");
			}
		} else
		{
			cuv.push_back(sSource[i]);
		}
	}
	if (cuv.size() > 0)
	{
		vOut.push_back(cuv);
	}
}
string LongToStr(long value)
{
	char szTmp[64];
	_ltoa(value, szTmp, 10);

	string res = szTmp;

	return res;
}
long ParseNumber(string sSrc, int &pos)
{
	long sign = 1, value = 0;

	if (sSrc[pos] == '-')
	{
		sign = -1;
		pos++;
	}

	bool bNone = true;
	while (sSrc[pos] >= '0' && sSrc[pos] <= '9')
	{
		value = value * 10 + sSrc[pos++] - '0';
		bNone = false;
	}

	return (bNone) ? sign : value * sign;
}
// <CTerm class>
class CTerm
{
public:
	CTerm()
	{
		memset(m_Powers, 0, sizeof(m_Powers));
		m_Constant = 0;
	}
	~CTerm() {};

	// members
	string ToString()
	{
		int i, j;
		string res = "";
		char szAlfa[32] = "abcdefghijklmnopqrstuvwxyz";
/*
		// sort after exponent
		for (i = 0; i < 26; i++)
			for (j = i + 1; j < 26; j++)
				if (m_Powers[szAlfa[j]] > m_Powers[szAlfa[i]])
				{
					char aux = szAlfa[i];
					szAlfa[i] = szAlfa[j];
					szAlfa[j] = aux;
				};;
*/
		bool bHasExpo = false;
		for (i = 0; i < 26; i++)
			if (m_Powers[szAlfa[i]] > 0)
			{
				bHasExpo = true;
				break;
			};

		if (ABS(m_Constant) > 1 || !bHasExpo)
		{
			res += LongToStr(ABS(m_Constant));					// the sign is put at the end
		} else
		if (m_Constant == 0)
		{
			res = "0";
		}

		if (m_Constant != 0)
		for (i = 0; i < 26; i++)
			if (m_Powers[szAlfa[i]] > 0)
			{
				if (res.size() > 0)
				{
					res += string("*");
				}
				res += szAlfa[i];
				if (m_Powers[szAlfa[i]] > 1)
				{
					res += string("^") + LongToStr(m_Powers[szAlfa[i]]);
				}
			}

		return res;
	}

	void FromString(string sSrc)
	{
		int nPos, i;

		memset(m_Powers, 0, sizeof(m_Powers));
		// erase spaces
		while ((nPos = sSrc.find(' ')) >= 0)
		{
			sSrc.erase(nPos, 1);
		}

		// parse constant
		i = 0;
		m_Constant = 1;

		// parse the variables and exponents
		while (i < sSrc.size())
			if (sSrc[i] >= 'a' && sSrc[i] <= 'z')
			{
				char letter = sSrc[i++];
				if (sSrc[i++] == '^')							// ^ sign
				{
					m_Powers[letter] += ParseNumber(sSrc, i);
				} else
				{
					m_Powers[letter]++;
				}
			} else
			if ((sSrc[i] >= '0' && sSrc[i] <= '9') || sSrc[i] == '-')
			{
				m_Constant *= ParseNumber(sSrc, i);
			} else
			{
				i++;
			}
	}

	// operators
	CTerm&	operator =	(const CTerm obj)
	{
		memcpy(m_Powers, obj.m_Powers, sizeof(obj.m_Powers));
		m_Constant = obj.m_Constant;

		return *this;
	}

	bool	operator == (const CTerm obj)
	{
		char ch;

		for (ch = 'a'; ch <= 'z'; ch++)
			if (m_Powers[ch] != obj.m_Powers[ch])
				return false;

		return true;								// can add now
	}

	bool	operator != (const CTerm obj)
	{
		return !(*this == obj);
	}

	bool	operator >	(const CTerm obj)
	{
		char ch;
		int count1, count2;


		count1 = count2 = 0;

		for (ch = 'a'; ch <= 'z'; ch++)
		{
			count1 += m_Powers[ch];
			count2 += obj.m_Powers[ch];
		}
		if (count1 > count2) return true;
		if (count1 < count2) return false;

		// count1 == count2
		for (ch = 'a'; ch <= 'z'; ch++)
		{
			if (m_Powers[ch] > obj.m_Powers[ch])
				return true;
			else 
			if (m_Powers[ch] < obj.m_Powers[ch])
				return false;
		}

		// same powers, can't compare -> must be added
	}

	bool	operator <	(const CTerm obj)
	{
		return !(*this == obj || *this > obj);
	}

	CTerm	operator +	(const CTerm obj)
	{
		if (*this != obj)
		{
			return *this;
		}

		m_Constant += obj.m_Constant;
	}

	CTerm	operator *	(const CTerm obj)
	{
		char ch;

		for (ch = 'a'; ch <= 'z'; ch++)
		{
			m_Powers[ch] += obj.m_Powers[ch];
		}

		m_Constant *= obj.m_Constant;

		return *this;
	}


public:
	// attributes
	int m_Powers[256];												// only 'a'..'z' used but what the heck...
	int m_Constant;
};
// </CTerm class>

list<CTerm> Poly1, Poly2, PolyFinal;



void ReadData()
{
#ifndef ONLINE_JUDGE
	freopen(FILE_INPUT, "rt", stdin);
#endif
	char szLine[4096];

	int nPoly = 0;
	while (gets(szLine))
	{
		nPoly++;
		//szLine[strlen(szLine) - 1] = 0;
		string sLine = szLine;

		int nPos;
		while ((nPos = sLine.find(' ')) >= 0)
		{
			sLine.erase(nPos, 1);
		}

		nPos = -2;
		while ((nPos = sLine.find('-', nPos + 2)) >= 0)
		{
			sLine.insert(nPos, "+");
		}

		vector<string> vTerms;
		SplitTokenString(vTerms, sLine, "+");
		
		int i;
		for (i = 0; i < vTerms.size(); i++)
		{
			CTerm t;
			t.FromString(vTerms[i]);

			if (nPoly == 1)
			{				
				Poly1.push_back(t);
			} else
			if (nPoly == 2)
			{
				Poly2.push_back(t);
			}
		}
	}
}

void Write(list<CTerm> poly)
{
	list<CTerm>::iterator iter;
	string sWrite = "";

	for (iter = poly.begin(); iter != poly.end(); iter++)
	{
		CTerm t = *iter;

		if (iter == poly.begin())
		{
			if (t.m_Constant < 0)
			{
				sWrite += "-";
			}
			if (t.m_Constant == 0 && poly.size() > 1)
				continue;

			sWrite += t.ToString();
		} else
		if (t.m_Constant != 0)
		{
			if (sWrite.size() > 0)
			{
				sWrite += (t.m_Constant < 0) ? " - " : " + ";
			}

			sWrite += t.ToString();
		}
	}
	printf("%s\n", sWrite.c_str());
}

void Solve()
{
	list<CTerm>::iterator iter1, iter2, iter;

	for (iter1 = Poly1.begin(); iter1 != Poly1.end(); iter1++)
		for (iter2 = Poly2.begin(); iter2 != Poly2.end(); iter2++)
		{
			CTerm t1 = *iter1;
			CTerm t2 = *iter2;

			CTerm t = t1 * t2;

			PolyFinal.push_back(t);
		};;

	// sort

	//Write(PolyFinal);
	PolyFinal.sort();
	PolyFinal.reverse();

	// combine similar terms
	for (iter = PolyFinal.begin(); iter != PolyFinal.end(); iter++)
	{
		iter1 = iter;
		iter1++;

		while (iter1 != PolyFinal.end())
		{
			CTerm &t1 = *iter;
			CTerm &t2 = *iter1;

			if (t1 == t2)
			{
				t1 + t2;							// :))

				PolyFinal.erase(iter1);
				iter1 = iter;
			}
			iter1++;
		}
	}

	Write(PolyFinal);
}


int main()
{
	ReadData();
	Solve();

	return 0;
}
