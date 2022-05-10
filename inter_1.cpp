#include <iostream>
#include <fstream>
#include <string>
#include <map>

void oper_(std::string);
void f_int(int, std::string);
void f_double(int, std::string);
void f_bool(int, std::string);
void f_string(int, std::string);
int f_cout(int, std::string);
void f_if(int, std::string);
void f_while(int, std::string);
bool cmp_si(std::string,char,std::string);
int math_oper(int, int, char );
using  namespace std;
std::map <std::string, int> map_int;
std::map <std::string, std::string> map_double;
std::map <std::string, std::string> map_bool;
std::map <std::string, std::string> map_string;

int main()
{
	char data[1000];
	std::ifstream ifout;
	ifout.open("pret.txt");
	while(!ifout.eof())
	{
		ifout.getline(data, 1000);
		oper_(data);
	}
}

void oper_(std::string str)
{
	std::string stri = "itiv";
	std::string strd = "dtivv";
	std::string strb = "ftbooll";
	std::string strtox = "tox";
	std::string strc = "druck";
	std::string strf = "payman";
	std::string strw = "wie";
	int j = 0;
	int count = 0;
	for(int i = 0; i < str.length(); ++i)
	{
		while(str[i] == stri[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == stri.length())
		{
			f_int(count, str);
			return;
		}
		while(str[i] == strd[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strd.length())
		{
			f_double(count, str);
			return;
		}
		while(str[i] == strb[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strb.length())
		{
			f_bool(count, str);
			return;
		}
		while(str[i] == strtox[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strtox.length())
		{
			f_string(count, str);
			return;
		}
		while(str[i] == strc[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strc.length())
		{
			f_cout(count, str);
			return;
		}
		while(str[i] == strf[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strf.length())
		{
			f_if(count, str);
			return;
		}
		while(str[i] == strw[j])
		{
			++i;
			++j;
			++count;
		}
		if(count == strw.length())
		{
			f_while(count, str);
			return;
		}
		else
		{
			std::cout << "error:" << std::endl; 
		}
		return;
	}
}

void f_int(int count, std::string str)
{
	int t = 0; // փ ոփ ոխ ա կա նի ա նվա ն տ ա ռերի քա նա կը
	std::string value = ""; // փ ոփ ոխ ա կա նի ա րժեքը
	std::string name = ""; // փ ոփ ոխ ա կա նի ա նունը
	if(str[count] != ' ')
	{
		std::cout << "error1: from f_int" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 97 && str[count] <= 122)
	{
		name += str[count];
		++t;
		++count;
	}
	if(t != 1)
	{
		std::cout << "error2: from f_int" << std::endl;
		exit(0);
	}
	if(str[count] != ' ')
	{
		std::cout << "error3: from f_int" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '~')
	{
		std::cout << "error4: from f_int" << std::endl;
		exit(0);
	}
	if(str[count] == '~')
	{
		++count;
	}
	while(str[count] == ' ')
	{
		++count;
	}
	int num = 0;
	char ch;
	while(str[count] >= 48 && str[count] <= 57)
	{
		num = num * 10;
		num += (str[count] - 48);
		++count;
	}
	while( str[count] == ' ')
	{
		++count;
	}
	if( str[count] == '/')
	{
		map_int.emplace(name, num);
		return;
	}
	int v = 0;
	if( str[count] == '+' || str[count] == '-' || str[count] == '*' || str[count] == '%')
	{
		ch = str[count];
		++v;
	}
	if( v == 1 )
	{ 
		++count;
	}
	while( str[count] == ' ')
	{
		++count;
	}
	int num2 = 0;
	while( str[count] >= 48 && str[count] <= 57)
	{
		num2 += (str[count] - 48);
		++count;
	}
	int result = math_oper(num, num2, ch);
`	map_int.emplace(name, result);
	if(str[count] != '/')
	{
		std::cout << "error5: from f_int" << std::endl;
		exit(0);
	}
	return;
}

void f_double(int count, std::string str)
{
	int k = 0; // ստ որա կետ երի քա նա կը
	int t = 0; // փ ոփ ոխ ա կա նի ա նվա ն տ ա ռերի քա նա կը
	std::string value = ""; // փ ոփ ոխ ա կա նի ա րժեքը
	std::string name ="";// փ ոփ ոխ ա կա նի ա նունը
	std::string log = "";
	if(str[count] != ' ')
	{
		std::cout << "error1: from f_double" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 97 && str[count] <= 122)
	{
		name += str[count];
		++t;
		++count;
	}
	if(t != 1)
	{
		std::cout << "error2: from f_double" << std::endl;
		exit(0);
	}
	if(str[count] != ' ')
	{
		std::cout << "error3: from f_double" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '~')
	{
		std::cout << "error4: from f_double" << std::endl;
		exit(0);
	}
	if(str[count] == '~')
	{
		++count;
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 48 && str[count] <= 57)
	{
		value += str[count];
		++count;
	}
	while(str[count] >= 48 && str[count] <= 57 || str[count] == 46)
	{
		value += str[count];
		if(str[count] == 46)
		{
			++k;
		}
		if(k > 1)
		{
			std::cout << "error5: from f_double" << std::endl;
			exit(0);
		}
		++count;
	}
	if(str[count] != '/')
	{
		std::cout << "error6: from f_double" << std::endl;
		exit(0);
	}
	map_double.emplace(name, value);
}

void f_bool(int count, std::string str)
{
	int t = 0; // փ ոփ ոխ ա կա նի ա նվա ն տ ա ռերի քա նա կը
	std::string value = ""; // փ ոփ ոխ ա կա նի ա րժեքը
	std::string name = ""; // փ ոփ ոխ ա կա նի ա նունը
	if(str[count] != ' ')
	{
		std::cout << "error1: from f_bool" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 97 && str[count] <= 122)
	{
		name += str[count];
		++t;
		++count;
	}
	if(t != 1)
	{
		std::cout << "error2: from f_bool" << std::endl;
		exit(0);
	}
	if(str[count] != ' ')
	{
		std::cout << "error3: from f_bool" << std::endl;
		exit(0);
	}
	if(str[count] == ' ')
	{
		++count;
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '~')
	{
		std::cout << "error4: from f_bool" << std::endl;
		exit(0);
	}
	if(str[count] == '~')
	{
		++count;
	}
	if(str[count] != ' ')
	{
		std::cout << "error5: from f_bool" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] == '0')
	{
		value += str[count];
		++count;
		if(str[count] != '/')
		{
			std::cout << "error6: from f_bool" << std::endl;
			exit(0);
		}
	}
	if(str[count] == '1')
	{
		value += str[count];
		++count;
		if(str[count] != '/')
		{
			std::cout << "error7: from f_bool" << std::endl;
			exit(0);
		}
	}
	map_bool.emplace(name, value);
}

void f_string(int count, std::string str)
{
	int t = 0; // փ ոփ ոխ ա կա նի ա նվա ն տ ա ռերի քա նա կը
	std::string value = ""; // փ ոփ ոխ ա կա նի ա րժեքը
	std::string name = ""; // փ ոփ ոխ ա կա նի ա նունը
	if(str[count] != ' ')
	{	
		std::cout << "error1: from f_string" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 65 && str[count] <= 90)
	{
		name += str[count];
		++t;
		++count;
	}
	if(t != 1)
	{
		t = 0;
		std::cout << "error2: from f_string" << std::endl;
		exit(0);
	}
	if(str[count] != ' ')
	{
		std::cout << "error3: from f_string" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '~')
	{
		std::cout << "error4: from f_string" << std::endl;
		exit(0);
	}
	if(str[count] == '~')
	{
		++count;
	}
	if(str[count] != ' ')
	{
		std::cout << "error5: from f_string" << std::endl;
		exit(0);
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '"')
	{
		std::cout << "error6: from f_string" << std::endl;
		exit(0);
	}
	if(str[count] == '"')
	{
		++count;
	}
	while(str[count] != '"')
	{
		value = value + str[count];
		++count;
	}
	if(str[count] == '"')
	{
		++count;
	}
	if(str[count] != '/')
	{
		std::cout << "error7: from f_string" << std::endl;
		exit(0);
	}
	map_string.emplace(name, value);
}

int f_cout(int count, std::string str)
{
	do
	{
		int t = 0; // փ ոփ ոխ ա կա նի ա նվա ն տ ա ռերի քա նա կը
		std::string name = ""; // փ ոփ ոխ ա կա նի ա նունը
		while(str[count] == ' ')
		{
			++count;
		}
		if(str[count] != ':')
		{
			std::cout << "error1: from f_cout" << std::endl;
			exit(0);
		}
		if(str[count] == ':')
		{
			++count;
		}
		if(str[count] != ':')
		{
			std::cout << "error2: from f_cout" << std::endl;
			exit(0);
		}
		if(str[count] == ':')
		{
			++count;
		}
		if(str[count] != ' ')
		{
			std::cout << "error3: from f_cout" << std::endl;
			exit(0);
		}
		while(str[count] == ' ')
		{
			++count;
		}
		if(str[count] >= 97 && str[count] <= 122)
		{
			name += str[count];
			++t;
			++count;
		}
		if(str[count] >= 65 && str[count] <= 90)
		{
			name += str[count];
			++t;
			++count;
		}
		if(t != 1)
		{
			std::cout << "error4: from f_cout" << std::endl;
			exit(0);
		}
		auto it1 = map_int.find(name);
		auto it2 = map_double.find(name);
		auto it3 = map_bool.find(name);
		auto it4 = map_string.find(name);
		if(name == it1 -> first)
		{
			std::cout << name << " = " << map_int[name] << std::endl;
			name = "";
			break;
		}
		if(name == it2 -> first)
		{
			std::cout << name << " = " << map_double[name] << std::endl;
			name = "";
			break;
		}
		if(name == it3 -> first)
		{
			std::cout << name << " = " << map_bool[name] << std::endl;
			name = "";
			break;
		}
		if(name == it4 -> first)
		{
			std::cout << name << " = " << map_string[name] << " ";
			name = "";
			break;
		}
		while(str[count] == ' ')
		{
			++count;
		}
	}while(str[count] != '/');  
		++count;
		return count;
}

void f_if(int count, std::string str)
{
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '(')
	{
		std::cout << "error1: from f_if" << std::endl;
		exit(0);
	}
	++count;
	while(str[count] == ' ')
	{
		++count;
	}
	std::string c = "";
	int com = 0;
	if(str[count] >= 97 && str[count] <= 122)
	{
		c = str[count];
		++count;
		++com;
	}
	if(com == 0 )
	{
		std::cout << "error variable" << std::endl;
		exit(0);
	}
	com = 0;
	while(str[count] == ' ')
	{
		++count;
	}
	char cmp;
	if(str[count] != '>' && str[count] != '<' && str[count] != '=')
	{
		std::cout << "error symbol" << std::endl;
		exit(0);
	}
	cmp = str[count];
	++count;
	std::string m = "";
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] >= 97 && str[count] <= 122)
	{
		m = str[count];
		++count;
		++com;
	}
	if(com == 0)
	{
		std::cout << "error symbol" << std::endl;
		exit(0);
	}
	com = 0;
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != ')')
	{
		std::cout << "Error2: from f_if" << std::endl;
	}
	if(str[count] == ')')
	{
		++count;
	}
	while(str[count] == ' ')
	{
		++count;
	}
	if(str[count] != '^')
	{
		std::cout << "error ^ si " << std::endl;
		exit(0);
	}
	++count;
	while(str[count] == ' ')
	{
		++count;
	}
	int count_com = 0;
	bool cmp_symbol = cmp_si(c, cmp, m);
	if(cmp_symbol == 0)
	{
		return;
	}
	if(cmp_symbol)
	{
		count_com = f_cout(count, str);
		cmp_symbol = 0;
	}
	count = count_com;
	if(str[count] != ' ')
	{
		std::cout << "error white space" << std::endl;
		exit(0);
	}
	++count;
	if(str[count] != '^')
	{
		std::cout << str[count];
		std::cout << "error ^ " << std::endl;
		exit(0);
	}
	return;
}

void f_while(int count, std::string str)
{
	int strcmp = 0;
	std::string strcmp1 = "";
	int i = count;
	count = 0;
	while(str[i] == ' ') 
	{
		++i;
	}
	while(str[i] != '(') 
	{
		std::cout << "error '(' " << std::endl;
		exit(0);
	}
	++i;
	while(str[i] == ' ') 
	{
		++i;
	}
	while(str[i] >= 48 && str[i] <= 57) 
	{   
		strcmp += (str[i] - 48);
		++i;
	}
	if( strcmp == 0 ) 
	{ 
		return; 
	}
	while(str[i] == ' ') 
	{
		++i;
	}
	if(str[i] != ')') 
	{
		std::cout << " error scope ')' " << std::endl;
		exit(0);
	}
	++i;
	if(strcmp) 
	{
		while(str[i] == ' ') 
		{
			++i;
		}
		if(str[i] != '^') 
		{
			std::cout << "error  '^' scope " << std::endl;
			exit(0);
		}
		++i;
		while(str[i] == ' ') 
		{
			++i;
		}
		if(str[i] != ':') 
		{
			std::cout << "error :: " << std::endl;
			exit(0);
		}
		while(str[i] == ':') 
		{
			++i;
			++count;
		}
		if(count != 2 ) 
		{
			std::cout << "error :: " << std::endl;
			exit(0);
		}
		count = 0;
		while(str[i] == ' ') 
		{
			++i;
		}
		if(str[i] >= 97 && str[i] <= 122) 
		{
			strcmp1 += str[i];
			++count;
			++i;
		}
		if(count != 1) 
		{
			std::cout << "error varible wie " << std::endl;
			exit(0);
		}
		while(str[i] == ' ') 
		{
			++i;
		}
		if(str[i] != '/' ) 
		{
			std::cout << "error / wie " << std::endl;
			exit(0);
		}
		++i;
		while(str[i] == ' ') 
		{
			++i;
		}
		if(str[i] != '^') 
		{
			std::cout << "print ^ scope " << std::endl;
			exit(0);
		}
		while(strcmp) 
		{
			strcmp--;
			std::cout << map_int[strcmp1] << " ";
		}
	} 
}

int math_oper(int num_1, int num_2, char symbol)
{
	if(symbol == '+')
	{
		num_1 += num_2;
		return num_1;
	}
	if(symbol == '-')
	{
		num_1 -= num_2;
		return num_1;
	}
	if(symbol == '*')
	{
		num_1 *= num_2;
		return num_1;
	}
	if(symbol == '/')
	{
		num_1 /= num_2;
		return num_1;
	}
	if(symbol == '%')
	{
		num_1 %= num_2;
		return num_1;
	}
}

bool cmp_si(std::string c, char cmp, std::string m)
{
	int num = map_int[c];
	int sum = map_int[m];
	if(cmp == '>')
	{
		if(num > sum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(cmp == '<')
	{
		if(num < sum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(cmp == '=')
	{
		if(num == sum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}
