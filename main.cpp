#include <iostream>
#include <string>
#include<random>
#include <vector>
#include "Tape.h"
#include "Sorting.h"

#define N 1000
#define M 100




using namespace std;
random_device rd;
mt19937 gen(rd());
//функция рандома
int random(int low, int high)
{
    uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int compare (const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b );
}



//создание временных лент
void create_tmp_tapes( int n, Tape tape){
    string s;
    ifstream file_in;
    Tape tape_tmp;

    try {
        file_in.open(tape.name);
        for (int i = 0; i < N; i += n) {
            int *tmp_tape = new int[n];
            for (int j = 0; j < n; j++) {
               file_in>>s;
                tmp_tape[j]= atoi(s.c_str());
            }
            qsort(tmp_tape, n, sizeof (int), compare);
            tape_tmp.name="tmp/"+ to_string(i)+".txt";
            tape_tmp.filling_input_tape(n,1,tmp_tape);
            delete[] tmp_tape;
        }
        file_in.close();
    }
    catch (const exception & exception) {
        cout<<exception.what();
    }
}



int main() {
    //Очистка директорий tmp и tapes
    const char* directory = "tmp/*";
    const int result_of_removing_tmp = system(string("rm -f " + string(directory)).c_str());
    directory = "tapes/*";
    const int result_of_removing_taples=system(string("rm -f " + string(directory)).c_str());
    if (result_of_removing_tmp == -1 || result_of_removing_taples==-1) {
        perror("Не удалось очистить директории tmp или tapes");
    }
    //определение размера временных лент
    int n = M / sizeof(int);
    if (n==0){
        n=1;
    }
    string tmp_path;
    Tape input_tape, output_tape;
    cout<<"Введите имя входного файла и имя выходного файла: ";
    cin>>input_tape.name;
    cin>>output_tape.name;
    input_tape.name="tapes/"+input_tape.name+".txt";
    output_tape.name="tapes/"+output_tape.name+".txt";
    int* random_array=new int[N];
    for(int i=0;i<N;i++){
        random_array[i]=random(0,100);
    }
    input_tape.filling_input_tape(N,1,random_array);
    delete[] random_array;
    create_tmp_tapes(n, input_tape);
    Sorting sorting;
    sorting.mergeSortedTapes(n,N,output_tape.name);

    return 0;
}
