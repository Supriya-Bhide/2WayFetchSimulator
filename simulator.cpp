/* 2 way fetch simulator */



#include "simulator.h"

/* 
Considering a hypothetical ISA that has

MOV D S
ADD D/O O
SUB D/O O
MUL D/O O

*/

template<typename T>
Fetcher<T>::Fetcher(){
    cout<<"Lookup table initialised\n";
};

/* template <typename T>
void Fetcher<T>::parseLine(string input, const char *delimiter)
{
    regex re("[ |,]");
    sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
    vector<string> tokens{first, last};
} */

template <typename T>
void Fetcher<T>::readFile(char fname[100])
{
    std::ifstream input( fname );
    std::string line, src, dest, opcode;
    int ins_count=0;
    
    // read file line by line
    while (std::getline(input, line))
    {
        //initialise stringstream variable to store read instruction for parsing
        std::stringstream stream(line);
        ins_count++;
        cout << "**************************\n";
        cout << ins_count << ") " << line << "\n";
 
        // parsing instruction to get opcode, source and destination
        std::getline(stream, opcode, ' ');
        std::getline(stream, src, ',');
        std::getline(stream, dest, ',');
        
        cout << "-----------------------------\n";
        cout << ins_count << ") " << opcode << "\n";
        cout << ins_count << ") " << src << "\n";
        cout << ins_count << ") " << dest << "\n";
        cout << "-----------------------------\n";
        
        checkIfNumber(src);

        // ins1 = new std::map<int, bool, bool>;
        // ins1.insert(std::tuple(1,0,0));
        ins1->insert(std::tuple(1,0,0));

        // lookupVar.insert({opcode,ins1});
    }
}

template <typename T>
bool Fetcher<T>::checkIfNumber(string operand)
{
    char op[10];
    strcpy(op, operand.c_str());

    if(isdigit(op[0]))
    {
        return 1;
    }
    else return 0;
}

int main()
{
    char fname[50];

    printf("Input-code-file:\n");
    scanf("%s",fname);

    Fetcher<int> f;
    f.readFile(fname);

    return 0;
}