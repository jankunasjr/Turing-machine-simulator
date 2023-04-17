#include <iostream>
#include <vector>                               
#include <fstream>                             
#include <conio.h>                        

using namespace std;

struct turing 
{
	string current_state;  
	char current_symbol;
	char new_symbol;                 
	char direction;
	string new_state;      
};

vector<turing>vec;
	
int main()
{
	string tape, answer, state = "0";
	int head;     
	turing temp;                                
	bool end_state = false, out = false, valid_file = false;                         
	char file[100];
	ifstream in;                                
	
	while (!valid_file)                
	{
		valid_file = true;                  
		cout << " Iveskite failo pavadinima: ";                 
		cin >> file;
		in.open(file);                            
		if(!in)      
		{                                
			cout << "Nepavyksta atidaryti failo" << endl;   
			valid_file = false;
		}                                 
	}
	in >> tape >> head;
	
	while (!in.eof()) 
	{          
		in >> temp.current_state;
		in >> temp.current_symbol;
		in >> temp.new_symbol;					
		in >> temp.direction;                         
		in >> temp.new_state;
		vec.push_back(temp);
	}
	in.close();
	
	string border1 = " ";
	char border2 = ' ';                          
	tape.insert(0,border1);                   
    tape.push_back(border2);
		
	while(true)
	{
		end_state = true;
		for(int i = 0; i < vec.size(); i++)
		{
			if(vec[i].current_symbol == tape[head] && vec[i].current_state == state)    
			{
				end_state = false;
				tape[head] = vec[i].new_symbol;                                        
				state = vec[i].new_state;
				
				if(vec[i].direction == 'R')
				{
					head++;                                       
				}else if(vec[i].direction == 'L')
				{                  
					head--;
				}
				cout << tape << endl;                             
			}
			if(tape[head] == ' ')
			{
				out = true;                                        
				break;
			}
		}                    
		if(out)
		{
			cout << "\n Programa sustojo, nes galvute yra uz juostos ribos" << endl;                        
			break;
		}
		if(end_state)
		{     
			cout << "\n Programa sustojo"<<endl;
			break;
		}
		if(kbhit())
		{
        	cout << "\n Programa buvo sustabdyta" << endl;     
        	break;
    	}
	}	
	cout << "\n Ar norite pasirinkti nauja faila? [taip/ne]" << endl;     
	vec.clear();
	cout<<" ";                                     
	cin >> answer;
	if(answer == "taip")
	{
		main();                                                         
	}else
	{		            
		return 0;
	}
}
	






