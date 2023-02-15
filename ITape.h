//
// Created by Камилла Балаева on 14.02.2023.
//

#ifndef YADRO_ITAPE_H
#define YADRO_ITAPE_H
#include <vector>

using namespace std;

class ITape {
   virtual void filling_input_tape(int limit,  int step,  int* number)=0;
    virtual int get_count_of_tape()=0;

};



#endif //YADRO_ITAPE_H
