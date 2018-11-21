/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
   ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****

    trimAl v1.4: a tool for automated alignment trimming in large-scale
                 phylogenetics analyses.

    readAl v1.4: a tool for automated alignment conversion among different
                 formats.

    2009-2015 Capella-Gutierrez S. and Gabaldon, T.
              [scapella, tgabaldon]@crg.es

    This file is part of trimAl/readAl.

    trimAl/readAl are free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, the last available version.

    trimAl/readAl are distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with trimAl/readAl. If not, see <http://www.gnu.org/licenses/>.

***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>

#include "../include/TimerFactory.h"
#include "../include/reportsystem.h"
#include "../include/defines.h"
#include "../include/values.h"
#include "../include/utils.h"

/**
 \brief Utilities class.
 This class contains shared methods to be used in multiple parts of the code.
 */
namespace utils {

    /**
     \brief Vector initialization.
     \param [out] vector The vector that will be initialized.
     \param tam The size of the vector.
     \param valor The initialization value that will of all positions of the vector.

     This method is used to initialize
     all positions of a vector with a given value.
     */
    inline void initlVect(int *vector, int tam, int valor)
    {
        for (int i = 0; i < tam; i++) vector[i] = valor;
    }

    /**
     \brief Vector initialization.
     \param [out] vector The vector that will be initialized.
     \param tam The size of the vector.
     \param valor The initialization value of all positions of the vector.

     This method is used to initialize
     all positions of a vector with a given value.
     */
    inline void initlVect(float *vector, int tam, float valor)
    {
        for (int i = 0; i < tam; i++) vector[i] = valor;
    }

    /**
     \brief Integer vector copying.
     \param vect1 Vector that we want to copy.
     \param [out] vect2 Destination vector of the copy.
     \param tam Vectors size.

     This method copies integer vector 1 to integer vector 2.
      */
    inline void copyVect(int *vect1, int *vect2, int tam)
    {
        for (int i = 0; i < tam; i++) vect2[i] = vect1[i];
    }

    /**
     \brief Float vector copying.
     \param vect1 Vector that we want to copy.
     \param [out] vect2 Destination vector of the copy.
     \param tam Vectors size.

     This method copies float vector 1 to float vector 2.
     */
    inline void copyVect(float *vect1, float *vect2, int tam)
    {
        for (int i = 0; i < tam; i++) vect2[i] = vect1[i];
    }

    /**
     \brief Round double to inferior integer method.
     \param number The number that will be rounded.
     \return the rounded number.

     This method rounds a double number to the inferior integer.
     */
    inline int roundToInf(double number)
    {

    //    return std::floor(number);
        return ((int) number);
    }

    /**
     \brief Round double to integer method.
     \param number The number that will be rounded.
     \return the rounded number.

     This method rounds a double number to a integer.
     */
    inline int roundInt(double number)
    {

    //    return std::round(number);
        return ((int) ((double) number + 0.5));
    }

    /**
     \brief Round double to greater integer method.
     \param number The number that will be rounded.
     \return the rounded number.

     This method rounds a double number to the greater integer.
     */
    inline int roundToSup(double number)
    {

    //    return std::ceil(number);
        return ((int) ((double) number + 1.0));
    }

    /**
     \brief Maximum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The maximum between the two given numbers.

     This method returns the maximum between the two numbers given as parameters.
     */
    inline int max(int x, int y)
    {

        if (x > y) return x;
        else return y;
    }

    /**
     \brief Maximum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The maximum between the two given numbers.

     This method returns the maximum between the two numbers given as parameters.
     */
    inline float max(float x, float y)
    {

        if (x > y) return x;
        else return y;
    }

    /**
     \brief Maximum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The maximum between the two given numbers.

     This method returns the maximum between the two numbers given as parameters.
     */
    inline double max(double x, double y)
    {

        if (x > y) return x;
        else return y;
    }

    /**
     \brief Minimum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The minumum between the two given numbers.

     This method returns the minimum between the two numbers given as parameters.
     */
    inline int min(int x, int y)
    {
        if (x < y) return x;
        else return y;
    }

    /**
     \brief Minimum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The minumum between the two given numbers.

     This method returns the minimum between the two numbers given as parameters.
     */
    inline float min(float x, float y)
    {

        if (x < y) return x;
        else return y;
    }

    /**
     \brief Minimum of two numbers method.
     \param x The first number.
     \param y The second number.
     \return The minumum between the two given numbers.

     This method returns the minimum between the two numbers given as parameters.
     */
    inline double min(double x, double y)
    {

        if (x < y) return x;
        else return y;
    }

    /**
     \brief String-is-number checking.
     \param num The string we want to check.
     \return \b true if the string is a number, \b false if not.

     This method checks if the given string is a number
     (taking in mind the possibility of floating numbers and scientific notation)
     */
    inline bool isNumber(char *num)
    {

        int tam = strlen(num);
        if (tam == 0) return false;
        int i, flt = 1, expn = 1, sgn = 1;

        for (i = 0; i < tam; i++) {
            if (num[i] == '.' && flt)
                flt = 0;

            else if (((num[i] == 'e') || (num[i] == 'E')) && expn)
                expn = 0;

            else if (((num[i] == '+') || (num[i] == '-')) && sgn) {
                if (!expn) sgn = 0;
            } else if (num[i] > '9' || num[i] < '0')
                return false;
        }

        return true;

    }

    /**
     \brief String comparing method.
     \param a The first string that will be compared.
     \param b The second string that will be compared.
     \return \b true if the two strings are the same, \b false if not.

     This method compares the two strings given,
     and returns \b true if the two strings are equal.
     */
    inline bool compare(char *a, char *b)
    {

        return (!strcmp(a, b));
    }

    /**
     \brief Removing spaces method.
     \param in The string that we want to clean.
     \param[out] out The destination of the clean string.

     This method removes spaces in the input string
     and put the result in the output string.
     */
    inline void removeSpaces(char *in, char *out)
    {

        unsigned int i, j = 0;

        for (i = 0; i < strlen(in); i++) {

            if (in[i] != ' ' && in[i] != '\t') {
                out[j] = in[i];
                j++;
            }
        }
        out[j] = '\0';
    }

    /**
     \brief Swapping elements method
     \param a One element to swap.
     \param b Other element to swap.

     This method swaps the values in a and b.
     */
    inline void swap(float *a, float *b)
    {

        float temp;

        temp = *a;
        *a = *b;
        *b = temp;

    }

    /**
     \brief Quicksort sorting method.
     \param list The vector that we want to sort.
     \param ini The first element of the vector.
     \param fin The last element of the vector.

     This method sorts the vector using the quicksort method.
     */
    inline void quicksort(float *list, int ini, int fin)
    {
        // NOTE Introspective sort seems better - JMaria
        float elem_div;
        int i, j;

        if ((ini >= fin) || (fin < 0))
            return;

        elem_div = list[fin];
        i = ini - 1;
        j = fin;

        while (true) {

            while (list[++i] < elem_div)
                if (i == fin)
                    break;

            while (list[--j] > elem_div)
                if (j == 0)
                    break;

            if (i < j)
                swap(&list[i], &list[j]);
            else
                break;
        }

        swap(&list[i], &list[fin]);

        quicksort(list, ini, i - 1);
        quicksort(list, i + 1, fin);
    }

    /**
     \brief Swapping elements method
     \param a One element to swap.
     \param b Other element to swap.

     This method swaps the values in a and b.
     */
    inline void swap(int *a, int *b)
    {
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;

    }

    /**
     \brief Quicksort sorting method.
     \param list The vector that we want to sort.
     \param ini The first element of the vector.
     \param fin The last element of the vector.

     This method sorts the vector using the quicksort method.
     */
    inline void quicksort(int *list, int ini, int fin)
    {
    // NOTE Introspective sort seems better - JMaria
        int i, j, elem_div;

        if ((ini >= fin) || (fin < 0))
            return;

        elem_div = list[fin];
        i = ini - 1;
        j = fin;

        while (true) {

            while (list[++i] < elem_div)
                if (i == fin)
                    break;

            while (list[--j] > elem_div)
                if (j == 0)
                    break;

            if (i < j)
                swap(&list[i], &list[j]);
            else
                break;
        }

        swap(&list[i], &list[fin]);

        quicksort(list, ini, i - 1);
        quicksort(list, i + 1, fin);
    }



    /**
     \brief Check if a given file exists and its size is greater than 0.
     \param file ifstream to check
     */
    inline bool checkFile(std::ifstream &file)
    {
        // Check if a given file exists and its size is greater than 0 
        long begin, end;

        // Check whether input file exists or not 
        if (!file)
            return false;

        // Check input file sizes. A valid file should have a size grater than 0 
        begin = file.tellg();
        file.seekg(0, std::ios::end);
        end = file.tellg();
        file.seekg(0, std::ios::beg);
        // Compare difference between file start and end.
        // Depending on result, return True or False 
        if (!(end - begin))
            return false;
        return true;
    }

    /**
     \brief Read a new line from current input stream.\n
     This function is better than standard one
      since cares of operative system compatibility.\n
     It is useful as well because removes tabs and blank spaces
      at lines at beginning/ending.\n
     \param file ifstream to read line from.
     \return \n
        Line that has been read or
        nullptr if there is nothing to read.\n
     */
    inline char *readLine(std::ifstream &file)
    {
        StartTiming("char* readLine(std::ifstream &file) ");
        // Read a new line from current input stream. This function is better than
        // standard one since cares of operative system compability. It is useful
        // as well because remove tabs and blank spaces at lines beginning/ending 

        int state;
        std::string nline;
        char *line = nullptr;

        // Check it the end of the file has been reached or not
        if (file.eof())
            return nullptr;

        /* Store first line found. For -Windows & MacOS compatibility- carriage return
        * is considered as well as a new line character */
    //    for( ; (c != '\n') && (c != '\r') && ((!file.eof())); file.read(&c, 1))
    //        nline.resize(nline.size() + 1, c);
        getline(file, nline);

        // Remove blank spaces & tabs from the beginning of the line
        state = nline.find(' ', 0);
        while (state != (int) std::string::npos && state == 0) {
            nline.erase(state, 1);
            state = nline.find(' ', state);
        }

        state = nline.find('\t', 0);
        while (state != (int) std::string::npos && state == 0) {
            nline.erase(state, 1);
            state = nline.find('\t', state);
        }

        /* If there is nothing to return, give back a nullptr pointer ... */
        if (nline.empty())
            return nullptr;

        // Otherwise, initialize the appropiate data structure,
        // dump the data and return it 
        line = new char[nline.size() + 1];
        strcpy(line, nline.c_str());
        return line;
    }

    /**
     \brief Read a new line from current input stream.\n
     This function is better than standard one
     since cares of operative system compatibility.\n
     It is useful as well because removes tabs
     and blank spaces at lines at beginning/ending.\n
     \param file ifstream to read line from.
     \return \n
      nullptr if there is nothing to read.\n
      Line that has been read.
    */
    inline char *readLine(std::istream &file)
    {
        // Read a new line from current input stream. This function is better than
        // standard one since cares of operative system compability. It is useful
        // as well because remove tabs and blank spaces at lines beginning/ending

        int state;
        char c = ' ';
        std::string nline;
        char *line = nullptr;

        // Check it the end of the file has been reached or not
        if (file.eof())
            return nullptr;


        /* Store first line found. For -Windows & MacOS compatibility- carriage return
        * is considered as well as a new line character */
    //    for( ; (c != '\n') && (c != '\r') && ((!file.eof())); file.read(&c, 1))
    //        nline.resize(nline.size() + 1, c);
        getline(file, nline);
        /* Remove blank spaces & tabs from the beginning of the line */

        state = nline.find(' ', 0);
        while (state != (int) std::string::npos && state == 0) {
            nline.erase(state, 1);
            state = nline.find(' ', state);
        }

        state = nline.find('\t', 0);
        while (state != (int) std::string::npos && state == 0) {
            nline.erase(state, 1);
            state = nline.find('\t', state);
        }

        // If there is nothing to return, give back a nullptr pointer ...
        if (nline.size() == 0)
            return nullptr;

        // Otherwise, initialize the appropiate data structure,
        // dump the data and return it
        line = new char[nline.size() + 1];
        strcpy(line, &nline[0]);
        return line;
    }

    /**
     \brief Remove all content surrounded by ("") or ([]).\n
            It warns as well when a mismatch for these flags is found. \n
     \param nline Line to be trimmed.
     \return
            Line trimmed of comments or
            nullptr if there has been a mismatch\n
     */
    inline char *trimLine(std::string nline)
    {
        // This function is used to remove comments in between a biological sequence.
        // Removes all content surrounded by ("") or ([]).
        // It warns as well when a mismatch for these flags is found

        int pos, next;
        char *line;

        // Set-up lower and upper limit to look for comments inside of input std::string
        pos = -1;

        // Identify comments inside of input sequence and remove it
        while (true) {
            pos = nline.find('\"', (pos + 1));

            // When there is not any more a comment inside of sequence,
            // go out from this loop 
            if (pos == (int) std::string::npos)
                break;

            // Look for closing flag
            next = nline.rfind('\"', nline.size());

            // If a pair of comments flags '"' is found, remove everything inbetween
            if ((int) nline.find('\"', (pos + 1)) == next) {
                nline.erase(pos, (next - pos + 1));
                pos = -1;
            }

            // If there is only one flag '"' for comments inside of sequence,
            // user should be warned about that
            if (pos == next) {
                debug.report(ErrorCode::PossibleMissmatch);
                return nullptr;
            }
        }

        // Look for other kind of comments, in this case those with []
        while (true) {
            pos = -1;
            next = -1;

            // Search for last opened bracket. It is supposed to be the first one for
            // being close
            while ((pos = nline.find('[', (pos + 1))) != (int) std::string::npos)
                next = pos;

            // If no opening bracket has been found.
            // Check if there is any closing one
            if (next == -1) {
                // There are not any bracket in input std::string
                if ((int) nline.find(']', 0) == (int) std::string::npos)
                    break;
                // Otherwise, warn about the error
                debug.report(ErrorCode::BracketsMissmatchFound);
                return nullptr;
            }

            // Look for closest closing bracket to the opening one found
            pos = nline.find(']', (next + 1));

            //If no closing bracket has been found. Warn about the mismatch
            if (pos == (int) std::string::npos) {
                debug.report(ErrorCode::BracketsMissmatchFound);
                return nullptr;
            }

            // When both brackets have been found, remove comments inbetween them
            nline.erase(next, (pos - next + 1));
        }

        // Check if after removing all comments from input std::string there is still part
        // of sequences or not
        if (nline.empty())
            return nullptr;

        // Initialize and store resulting sequence into an appropiate structure
        line = new char[nline.size() + 1];
        strcpy(line, &nline[0]);

        return line;
    }

    /**
     \brief Reverses a string
     \param toReverse String to get a reversed copy.
     \return Reversed string of toReverse.
     */
    inline std::string getReverse(std::string toReverse)
    {

        std::string line(toReverse.size(), ' ');
        size_t i;

        for (i = toReverse.size() - 1; i >= 0; i--)
            line += toReverse[i];
        return line;
    }

    /**
     \brief Removes a determined char from the string
     \param c Character to remove from line
     \param line String to remove c from.
     \return New string without c character
     */
    inline std::string removeCharacter(char c, std::string line)
    {

        size_t pos;

        pos = line.find(c, 0);
        while (pos != (int) std::string::npos) {
            line.erase(pos, 1);
            pos = line.find(c, pos);
        }

        return line;
    }

    /**
     \brief Checks an alignment type
     \param seqNumber Number of sequences to check it's type.
     \param residNumber Number of residues of the alignment.
     \param sequences Sequences pointer
     \return Integer that represents the alignment type.
     */
    inline int checkAlignmentType(int seqNumber,
                                  int residNumber,
                                  std::string *sequences)
                                  {

        int i, j, k, l, hitDNA, hitRNA, degenerate, gDNA, gRNA, extDNA, extRNA;
        float ratioDNA, ratioRNA;
        // Standard tables
        char listRNA[11] = "AGCUNagcun";
        char listDNA[11] = "AGCTNagctn";

        // Degenerate Nucleotides codes
        char degeneratedCodes[21] = "MmRrWwSsYyKkVvHhDdBb";

        // For each sequences, this method locks at the 100 letters (excluding gaps).
        // The method is able to distinguish between pure DNA/RNA nucleotides or those
        // containing degenerate Nucleotide letters
        for (i = 0, gDNA = 0, gRNA = 0, extDNA = 0, extRNA = 0; i < seqNumber; i++) {

            // Looks at the 100 letters (excluding gaps) while doesn's get the sequence's end
            // When there are less than a 100 characters, break the loop before reaching that limit

            residNumber = (int) sequences[i].size();
            for (j = 0, k = 0, hitDNA = 0, hitRNA = 0, degenerate = 0; j < residNumber; j++)
                if (sequences[i][j] != '-' && sequences[i][j] != '.' && sequences[i][j] != '?') {
                    k++;

                    /* Recognizes between DNA and RNA. */
                    for (l = 0; l < (int) strlen(listDNA); l++)
                        if (listDNA[l] == sequences[i][j])
                            hitDNA++;

                    for (l = 0; l < (int) strlen(listRNA); l++)
                        if (listRNA[l] == sequences[i][j])
                            hitRNA++;

                    for (l = 0; l < (int) strlen(degeneratedCodes); l++)
                        if (degeneratedCodes[l] == sequences[i][j])
                            degenerate++;
                }

            // If input sequences have less than 95% of nucleotides, even when residues
            // are treated with degenerated codes, consider the input file as containing
            // amino-acidic sequences. 
            ratioDNA = float(degenerate + hitDNA) / k;
            ratioRNA = float(degenerate + hitRNA) / k;

            if (ratioDNA < 0.95 && ratioRNA < 0.95)
                return SequenceTypes::AA;

                // Identify precisely if nucleotides sequences are DNA/RNA strict or
                // any degenerate code has been used in the sequence
            else if (hitRNA > hitDNA && degenerate == 0)
                gRNA++;
            else if (hitRNA > hitDNA && degenerate != 0)
                extRNA++;
            else if (hitRNA < hitDNA && degenerate == 0)
                gDNA++;
            else if (hitRNA < hitDNA && degenerate != 0)
                extDNA++;
        }
        // Return the datatype with greater values, considering always degenerate
        // codes 
        if (extDNA != 0 && extDNA > extRNA)
            return (SequenceTypes::DNA | SequenceTypes::DEG);
        else if (extRNA != 0 && extDNA < extRNA)
            return (SequenceTypes::RNA | SequenceTypes::DEG);
        else if (gRNA > gDNA)
            return SequenceTypes::RNA;
        else if (gDNA >= gRNA)
            return SequenceTypes::DNA;
        else
            return SequenceTypes::NotDefined;
    }


    /**
     \brief Reads a line and converts it to an array of number
     \param line Line to convert to array of ints
     \return Pointer to an array of numbers that contains line
     */
    inline int *readNumbers(std::string line)
    {

        int i, nElems = 0;
        static int *numbers;

        size_t comma, separ, init;

        comma = size_t(-1);
        while ((comma = line.find(',', comma + 1)) != (int) std::string::npos)
            nElems += 2;
        nElems += 2;

        numbers = new int[nElems + 1];
        numbers[0] = nElems;

        init = 0;
        i = 1;

        do {
            comma = line.find(',', init);
            separ = line.find('-', init);

            if (((separ < comma) || (comma == (int) std::string::npos)) && (separ != (int) std::string::npos)) {
                numbers[i++] = atoi(line.substr(init, separ - init).c_str());
                numbers[i++] = atoi(line.substr(separ + 1, comma - separ - 1).c_str());
                init = comma + 1;
            } else if ((separ > comma) || (separ == (int) std::string::npos)) {
                numbers[i++] = atoi(line.substr(init, comma - init).c_str());
                numbers[i++] = atoi(line.substr(init, comma - init).c_str());
                init = comma + 1;
            }

            if (numbers[i - 2] < 0)
                return nullptr;
            if (numbers[i - 1] < numbers[i - 2])
                return nullptr;
            if (comma == (int) std::string::npos)
                break;

        } while (true);

        return numbers;
    }

    /**
     \brief Swaps double pointers.
     \param a Double pointer A
     \param b Double pointer B
    */
    inline void swap(int **a, int **b)
    {
        int *temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    /**
     \brief Quicksort sorting method.
     \param vect The vector that we want to sort.
     \param ini The first element of the vector.
     \param fin The last element of the vector.
    */
    inline void quicksort(int **vect, int ini, int fin)
    {
    // NOTE Introspective sort seems better - JMaria
        float elem_div;
        int i, j;

        if ((ini >= fin) || (fin < 0))
            return;

        elem_div = vect[fin][0];
        i = ini - 1;
        j = fin;

        while (true) {

            while (vect[++i][0] < elem_div) if (i == fin) break;
            while (vect[--j][0] > elem_div) if (j == 0) break;

            if (i < j) swap(&vect[i], &vect[j]);
            else break;

        }

        swap(&vect[i], &vect[fin]);

        quicksort(vect, ini, i - 1);
        quicksort(vect, i + 1, fin);

    }



    /**
     \brief Method to check for a pattern in a string.\n
            The method will check, character by character of the first string if
             there is some equality for each character in the pattern.
            When done, it will calculate the fraction of characters
             present in the pattern and compare to the threshold argument.
     \param data string that will be compared against a pattern
     \param pattern string that contains the pattern.
     \param threshold minimum ratio of hits to consider the pattern valid
     \todo Give a good description for this function.
     */
    inline bool lookForPattern(const std::string& data,
                               const std::string& pattern,
                               const float threshold)
                               {

        float count = 0;
        int i, j;

        for (i = 0; i < (int) data.size(); i++) {
            for (j = 0; j < (int) pattern.size(); j++) {
                if (toupper(data[i]) == toupper(pattern[j])) {
                    count++;
                    break;
                }
            }
        }

        return (count / data.size()) >= threshold;
    }


    /**
     \brief Checks the color that has to be used on the output report
     \param res Resiude to check its color
     \param column Column to which this residue belongs.
     \return Char that represents the color to be used.
    */
    inline char determineColor(char res, const std::string& column)
    {

        if (toupper(res) == 'G')
            return 'o';

        else if (toupper(res) == 'P')
            return 'y';

        else if (res != '-') {
            switch (toupper(res)) {

                // (W, L, V, I, M, F): {50%, p}{60%, wlvimafcyhp}
                case 87:
                case 76:
                case 86:
                case 73:
                case 77:
                case 70:
                    if (lookForPattern(column, "p", 0.5)) return 'b';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.6)) return 'b';
                    else return 'w';



                    // (A): {50%, p}{60%, wlvimafcyhp}{85% t,s,g}
                case 65:
                    if (lookForPattern(column, "p", 0.5)) return 'b';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.6)) return 'b';
                    else if (lookForPattern(column, "t", 0.85)) return 'b';
                    else if (lookForPattern(column, "s", 0.85)) return 'b';
                    else if (lookForPattern(column, "g", 0.85)) return 'b';
                    else return 'w';



                    // BLUE: (C): {50%, p}{60%, wlvimafcyhp}{85% s}
                    // PINK: (C): {85%, c}
                case 67:
                    if (lookForPattern(column, "p", 0.5)) return 'b';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.6)) return 'b';
                    else if (lookForPattern(column, "s", 0.85)) return 'b';
                    else if (lookForPattern(column, "c", 0.85)) return 'p';
                    else return 'w';



                    // (K, R): {60%, kr}{85%, q}
                case 75:
                case 82:
                    if (lookForPattern(column, "kr", 0.6)) return 'r';
                    else if (lookForPattern(column, "q", 0.85)) return 'r';
                    else return 'w';



                    // (T): {50%, ts}{60%, wlvimafcyhp }
                case 84:
                    if (lookForPattern(column, "ts", 0.5)) return 'g';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.6)) return 'g';
                    else return 'w';



                    // (S): {50%, ts}{80%, wlvimafcyhp }
                case 83:
                    if (lookForPattern(column, "ts", 0.5)) return 'g';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.8)) return 'g';
                    else return 'w';



                    // (N): {50%, n}{85%, d }
                case 78:
                    if (lookForPattern(column, "n", 0.5)) return 'g';
                    else if (lookForPattern(column, "d", 0.85)) return 'g';
                    else return 'w';



                    // (Q): {50%, qe}{60%, kr}
                case 81:
                    if (lookForPattern(column, "qe", 0.5)) return 'g';
                    else if (lookForPattern(column, "kr", 0.6)) return 'g';
                    else return 'w';



                    // (D): {50%, de, n}
                case 68:
                    if (lookForPattern(column, "de", 0.5)) return 'm';
                    else if (lookForPattern(column, "n", 0.5)) return 'm';
                    else return 'w';



                    // (E): {50%, de,qe}
                case 69:
                    if (lookForPattern(column, "de", 0.5)) return 'm';
                    else if (lookForPattern(column, "qe", 0.5)) return 'm';
                    else return 'w';



                    // (H,Y): {50%, p}{60%, wlvimafcyhp}
                case 72:
                case 89:
                    if (lookForPattern(column, "p", 0.5)) return 'c';
                    else if (lookForPattern(column, "wlvimafcyhp", 0.5)) return 'c';
                    else return 'w';

                default:
                    return 'w';
            }
        }
        return 'w';
    }

    /**
     \brief Function that replaces a substring
              with another substring in a string.
            It does not make a copy of the original string, but modifies it.
     \param [in,out] subject String to be modified
     \param search Substring to search and change
     \param replace Substring to put in place of search
     */
    inline void ReplaceStringInPlace(std::string &subject,
                                     const std::string &search,
                                     const std::string &replace)
                                     {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }

    /**
     \brief Function that replaces a substring
             with another substring in a string.
            It makes a copy of the original string.
     \param [in] subject String to be modified
     \param search Substring to search and change
     \param replace Substring to put in place of search
     */
    inline std::string ReplaceString(std::string subject,
                                     const std::string &search,
                                     const std::string &replace)
                                     {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }

    /**
     \brief Function that gives the gap classification of a column of values.
     \param gapValue Number of gaps present in the column.
     \param sequenNumber Number of sequences.
     \return Int representing the classification of this gap value.
     */
    inline int GetGapStep(int *gapValue, int sequenNumber)
    {
        // Special cases. Upper and Lower limits.
        if (*gapValue == 0)
            return 11;

        if (*gapValue == sequenNumber)
            return 0;

        float relativeGap = 1.F - float(*gapValue) / sequenNumber;

        if (relativeGap >= .750)
            return 10;
        if (relativeGap >= .500)
            return 9;
        if (relativeGap >= .350)
            return 8;
        if (relativeGap >= .250)
            return 7;
        if (relativeGap >= .200)
            return 6;
        if (relativeGap >= .150)
            return 5;
        if (relativeGap >= .100)
            return 4;
        if (relativeGap >= .050)
            return 3;
        if (relativeGap >= .001)
            return 2;
        return 1;
    }

    /**
     \brief Function that gives the gap classification of a column of values.\n
     This function should work faster than it's sister
       utils::GetGapStep(int * gapValue, int sequenNumber),
       as it uses a precomputed (by the user)
       inverseSequenNumber (1F / newAlignment::sequenNumber),
       instead of calculating it over again each time the function
       is called (which is equal to number of residues). \n
     This comes with a precision cost that shouldn't be a problem.
     \param gapValue Number of gaps present in the column.
     \param inverseSequenNumber Inverse of number of sequences. (1F / sequenNumber)
     \return Int representing the classification of this gap value.
     */
    inline int GetGapStep(int *gapValue, float inverseSequenNumber)
    {
        // Special cases. Upper and Lower limits.
        if (*gapValue == 0)
            return 11;

        float relativeGap = 1.F - float(*gapValue) * inverseSequenNumber;

        if (relativeGap == 0.F)
            return 0;
        if (relativeGap >= .750F)
            return 10;
        if (relativeGap >= .500F)
            return 9;
        if (relativeGap >= .350F)
            return 8;
        if (relativeGap >= .250F)
            return 7;
        if (relativeGap >= .200F)
            return 6;
        if (relativeGap >= .150F)
            return 5;
        if (relativeGap >= .100F)
            return 4;
        if (relativeGap >= .050F)
            return 3;
        if (relativeGap >= .001F)
            return 2;
        return 1;
    }

    /**
     \brief Function that gives the
      similarity classification of a column of values.
     \param simValue Similarity value.
     \return Int representing the classification of this gap value.
     */
    inline int GetSimStep(float *simValue)
    {

        if (*simValue == 0.F)
            return 11;
        if (*simValue == 1.F)
            return 0;
        if (*simValue >= .750F)
            return 10;
        if (*simValue >= .500F)
            return 9;
        if (*simValue >= .250F)
            return 8;
        if (*simValue >= .100F)
            return 7;
        if (*simValue >= .010F)
            return 6;
        if (*simValue >= .001F)
            return 5;
        if (*simValue >= 1e-4F)
            return 4;
        if (*simValue >= 1e-5F)
            return 3;
        if (*simValue >= 1e-6F)
            return 2;
        return 1;
    }

    /**
     \brief Function that gives the
      consistency classification of a column of values.
     \param consValue Consistency value.
     \return Int representing the classification of this gap value.
     */
    inline int GetConsStep(float *consValue)
    {
        // Special cases. Upper and Lower limits.
        if (*consValue == 1.F)
            return 11;
        if (*consValue == 0.F)
            return 0;

        if (*consValue >= .750)
            return 10;
        if (*consValue >= .500)
            return 9;
        if (*consValue >= .350)
            return 8;
        if (*consValue >= .250)
            return 7;
        if (*consValue >= .200)
            return 6;
        if (*consValue >= .150)
            return 5;
        if (*consValue >= .100)
            return 4;
        if (*consValue >= .050)
            return 3;
        if (*consValue >= .001)
            return 2;
        return 1;
    }

      /**
     
     
     */
    inline char toUpper(char c)
    {
        return std::toupper(c);
        if (c >= 'a' and c <= 'z')
            return c & (~(1<<5));
        return c;
    }


    inline void streamSVG(float *x, float *y,
                          int num, std::string *lineName,
                          std::string *lineColor, std::string *chartTitle,
                          std::string *filename)
                          {
        static std::ofstream file;
        static std::stringstream legend;
        static float lastX = INFINITY;
        static std::vector<std::string> linesLegend = std::vector<std::string>();
        static FILE *tmpFile;

        int
                whiteboxWidth = 1300,
                whiteboxHeight = 650,

                grayboxWidth = 1500,
                grayboxHeight = 900;

        float
                legendRatio = 0.175F,

                widthRatio = 0.5F,
                heightRatio = 0.75F,

                whiteboxDeltaHeight
                = whiteboxHeight * 0.05F,

                fontSize = whiteboxHeight * 0.02F;

        static float
                originX,
                originY,
                chartWidth,
                chartHeight;

        if (filename && chartTitle) {
            file.open(*filename);
            tmpFile = std::tmpfile();
            // svg header
            file << "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" version=\"1.1\" "
                << "height=\"" << grayboxHeight << "\" "
                << "width=\"" << grayboxWidth << "\">" << "\n";

            // White box
            file << "<rect "
                << "x=\"" << (grayboxWidth - whiteboxWidth) * widthRatio << "\" "
                << "width=\"" << whiteboxWidth * (1.F - legendRatio) << "\" "
                << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio << "\" "
                << "height=\"" << whiteboxHeight << "\" "
                << "style=\"fill:white; stroke:black; stroke-width:2\" "
                << "/>" << "\n";

            // Header text
            file << "<text text-anchor=\"middle\" "
                << "x=\"" << grayboxWidth * 0.5F << "\" "
                << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio * 0.75F << "\" "
                << "font-size=\"" << (grayboxHeight - whiteboxHeight) * heightRatio * 10.F / chartTitle->length() << "\" "
                << ">"
                << *chartTitle
                << "</text>" << "\n";

            // Horizontal lines
            for (int xx = 0; xx < 11; xx++) {
                // X axis lines
                file << "<line "
                    << "x1=\"" << (grayboxWidth - whiteboxWidth) * widthRatio << "\" "
                    << "y1=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + (whiteboxHeight - whiteboxDeltaHeight) * (xx * 0.1F) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "x2=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) << "\" "
                    << "y2=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + (whiteboxHeight - whiteboxDeltaHeight) * (xx * 0.1F) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "style=\"stroke:black;stroke-width:1\" "
                    << "stroke-dasharray=\"1, 1\" "
                    << "opacity=\"0.5\"/>" << "\n";

                // Labels
                file << "<text "
                    << "xx=\"" << (grayboxWidth - whiteboxWidth) * widthRatio * 0.95F << "\" "
                    << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + (whiteboxHeight - whiteboxDeltaHeight) * (xx * 0.1F) + (0.25F * fontSize) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "text-anchor=\"end\" "
                    << "xml:space=\"preserve\" "
                    << "font-size=\"" << fontSize << "\">"
                    << (10 - xx) / 10.F
                    << "</text>" << "\n";
            }

            // Horizontal lines
            for (int xx2 = 0; xx2 < 11; xx2++) {
                // X axis lines
                file << "<line "
                    << "x1=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + (whiteboxWidth * (1.F - legendRatio) - whiteboxDeltaHeight) * (xx2 * 0.1F) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "y1=\"" << (grayboxHeight - whiteboxHeight) * heightRatio << "\" "
                    << "x2=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + (whiteboxWidth * (1.F - legendRatio) - whiteboxDeltaHeight) * (xx2 * 0.1F) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "y2=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + whiteboxHeight << "\" "
                    << "style=\"stroke:black;stroke-width:1\" "
                    << "stroke-dasharray=\"1, 1\" "
                    << "opacity=\"0.5\"/>" << "\n";

                // Labels
                file << "<text "
                    << "xx2=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + (whiteboxWidth * (1.F - legendRatio) - whiteboxDeltaHeight) * (xx2 * 0.1F) + (whiteboxDeltaHeight * 0.5F) << "\" "
                    << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + whiteboxHeight * 1.05F << "\" "
                    << "text-anchor=\"middle\" "
                    << "xml:space=\"preserve\" "
                    << "font-size=\"" << fontSize << "\">"
                    << xx2 * 10 << " %"
                    << "</text>" << "\n";
            }

            originX = (grayboxWidth - whiteboxWidth) * widthRatio + (whiteboxDeltaHeight * 0.5F);
            originY = (grayboxHeight - whiteboxHeight) * heightRatio + (whiteboxHeight - whiteboxDeltaHeight * 0.5F);
            chartWidth = (whiteboxWidth * (1.F - legendRatio) - whiteboxDeltaHeight);
            chartHeight = -(whiteboxHeight - whiteboxDeltaHeight);
        } else if (x != NULL && y != NULL && lineColor != NULL) {
            if (*x < lastX) {
                if (lastX != INFINITY) {
                    file << "\"/>" << "\n";
                }
                linesLegend.emplace_back(*lineColor + ";" + *lineName);
                file << "<polyline stroke-linecap=\"round\" "
                    << "style=\"fill:none;stroke:" << *lineColor << ";stroke-width:0.8\" opacity=\"0.8\" points=\"";
            }
            file << originX + *x * chartWidth << ","
                << originY + *y * chartHeight << " ";

            std::fputs("<circle cx=\"", tmpFile);
            std::fputs(std::to_string(originX + *x * chartWidth).c_str(), tmpFile);
            std::fputs("\" cy=\"", tmpFile);
            std::fputs(std::to_string((originY + *y * chartHeight)).c_str(), tmpFile);
            std::fputs("\" r=\"2\" stroke=\"black\" stroke-width=\"0.1\" fill=\"", tmpFile);
            std::fputs(lineColor->c_str(), tmpFile);
            std::fputs("\" />\n", tmpFile);

            lastX = *x;
        } else {
            file << "\"/>" << "\n";

            float deltaHeigth = whiteboxHeight / (float) (linesLegend.size() + 1);
            deltaHeigth = std::min(whiteboxHeight * 0.12F, deltaHeigth);
            float height = whiteboxWidth * legendRatio * 0.1F;

            // Legend box
            file << "<rect "
                << "x=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + 6 << "\" "
                << "width=\"" << whiteboxWidth * legendRatio << "\" "
                << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio << "\" "
                << "height=\"" << deltaHeigth * (linesLegend.size() + 1) << "\" "
                << "style=\"fill:white; stroke:black; stroke-width:2\" "
                << "fill-opacity=\"0.25\" "
                << "/>" << "\n";

            file << "<text "
                << "x=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + whiteboxWidth * legendRatio * 0.5F << "\" "
                << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + deltaHeigth * 0 + deltaHeigth * 0.5F << "\" "
                << "text-anchor=\"middle\" "
                << "xml:space=\"preserve\" "
                << "font-size=\"" << fontSize * 2 << "\">"
                << "Statistics"
                << "</text>" << "\n";

            file << "<line "
                << "x1=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + 12 << "\" "
                << "x2=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + whiteboxWidth * legendRatio * 1.F << "\" "
                << "y1=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + deltaHeigth * 0.3F + deltaHeigth * 0.5F << "\" "
                << "y2=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + deltaHeigth * 0.3F + deltaHeigth * 0.5F << "\" "
                << "style=\"stroke:black;stroke-width:2\" />" << "\n";


            for (int x = 0; x < linesLegend.size(); x++) {
                file << "<rect "
                    << "x=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + whiteboxWidth * legendRatio * 0.1F << "\" "
                    << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + deltaHeigth * (x + 1) + deltaHeigth * 0.5F - height * 0.5F - fontSize * 0.25F << "\" "
                    << "width=\"" << height << "\" "
                    << "height=\"" << height << "\" "
                    << "style=\"fill:" << strtok(&linesLegend[x][0], ";") << "; stroke:black; stroke-width:2\" "
                    << "fill-opacity=\"0.75\" "
                    << "/>" << "\n";

                file << "<text "
                    << "x=\"" << (grayboxWidth - whiteboxWidth) * widthRatio + whiteboxWidth * (1.F - legendRatio) + whiteboxWidth * legendRatio * 0.5F << "\" "
                    << "y=\"" << (grayboxHeight - whiteboxHeight) * heightRatio + deltaHeigth * (x + 1) + deltaHeigth * 0.5F << "\" "
                    << "text-anchor=\"middle\" "
                    << "xml:space=\"preserve\" "
                    << "font-size=\"" << fontSize << "\">"
                    << strtok(NULL, "")
                    << "</text>" << "\n";
            }
            // svg footer

            char *line = new char[300];
            std::rewind(tmpFile);
            while (true) {
                if (fgets(line, 300, tmpFile) == nullptr) break;
                file << line;
            }
            delete[] line;

            file << "</svg>";
            file.close();
        }
    }

};



#endif
