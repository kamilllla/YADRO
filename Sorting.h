//
// Created by Камилла Балаева on 15.02.2023.
//

#ifndef YADRO_SORTING_H
#define YADRO_SORTING_H
#include <iostream>
#include "Tape.h"

using namespace std;
class Sorting {
public:
    void mergeSorted( string path1, string path2, string path_out) {
        int s = 0;
        int s2 = 0;
        int size1 = 0, size2 = 0, i = 0, j = 0;
        Tape tmp_tape;
        tmp_tape.name = path1;
        size1 = tmp_tape.get_count_of_tape();
        tmp_tape.name = path2;
        size2 = tmp_tape.get_count_of_tape();

        ifstream if_stream1;
        ifstream if_stream2;
        ofstream file_out;

        try {
            if_stream1.open(path1);
            if_stream1 >> s;
            if_stream2.open(path2);
            if_stream2 >> s2;
            file_out.open(path_out);
            while (i < size1 && j < size2) {
                if (s <= s2) {

                    file_out << s << ' ';
                    i++;
                    if_stream1 >> s;
                } else {

                    file_out << s2 << ' ';
                    j++;
                    if_stream2 >> s2;
                }

            }
            while (i < size1) {
                file_out << s << ' ';
                i++;
                if_stream1 >> s;
            }
            while (j < size2) {
                file_out << s2 << ' ';
                j++;
                if_stream2 >> s2;
            }
            if_stream1.close();
            if_stream2.close();
            file_out.close();
        }
        catch (const exception &exception) {
            cout << exception.what();
        }
    }


        void mergeSortedTapes(int n, int N, string out_file) {
            ifstream ifile;
            ofstream ofile;
            string tmp_path2, tmp_path, s;
            int i = 0;
            tmp_path = "tmp/" + to_string(i) + ".txt";
            tmp_path2 = "tmp/" + to_string(i += n) + ".txt";

            mergeSorted(tmp_path, tmp_path2, out_file);

            for (i += n; i < N; i += n) {

                tmp_path = "tmp/" + to_string(i) + ".txt";
                mergeSorted(tmp_path, out_file, out_file);

            }

        }
    };

#endif //YADRO_SORTING_H
