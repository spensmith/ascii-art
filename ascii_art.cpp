//
// Created by Spencer Smith on 1/23/21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

int main() {
    // greeting
    cout << "Now running initials.cpp.\n\n";
    string filename = "ascii_art.txt";
    ifstream the_file;
    the_file.open(filename);

    // check to see if the file can be opened
    if(!the_file)
    {
        cerr << "Cannot open file: " << filename << ".\n";
        return 1;
    }

    string user_input;
    cout << "Please enter what you would like to convert to ASCII-ART: ";
    getline (cin,user_input);
    cout << "You have entered " << user_input << ".\n\n";
    string output_array[7] = {"", "", "", "", "", "", ""};
    for (char &c: user_input) {
        ifstream this_chars_file;
        this_chars_file.open(filename);
        string line_in_file;
        if (c == ' ') {
            for (int i = 0; i <= 6; i++) {
                output_array[i] = output_array[i] + "     ";
            } // for i
        } // if c is a space
        while(getline(this_chars_file, line_in_file))
        {
            istringstream string_stream_variable (line_in_file);
            string line_as_string = string_stream_variable.str();
            if (tolower(c) == tolower(line_as_string.at(0))) {
                for (int one_or_zero_line = 0; one_or_zero_line <= 6; one_or_zero_line++) {
                    getline(this_chars_file, line_in_file);
                    istringstream ssv (line_in_file);
                    string las = ssv.str();
                    for (char &one_or_zero: las) {
                        if (one_or_zero == '1') {
                            output_array[one_or_zero_line] = output_array[one_or_zero_line] + c;
                        } // if equals 1
                        if (one_or_zero == '0') {
                            output_array[one_or_zero_line] = output_array[one_or_zero_line] + ' ';
                        } // if equals zero
                    } // for one_or_zero in las
                } // for one_or_zero_line in file
                for (int i = 0; i <= 6; i++) {
                    output_array[i] = output_array[i] + "  ";
                } // for i
            } // if line_as_string
        } // while getline
    } // for c in char

    // displaying values
    for (int z = 0; z <= 6; z++) {
        cout << output_array[z] << "\n";
    } // for z
    cout << "\nAll done.\n";
    return 0;
}