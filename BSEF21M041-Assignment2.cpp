#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


            //HELPER FUNCTIONS


bool isValidBit(int bit)
{
    return bit == 0 || bit == 1;
}

int computeDecimal(int number)
{
    int i = 0;
    int decNumber = 0;
    while (number > 0)
    {
        int remainder = number % 10;
        number = number / 10;
        decNumber = decNumber + (remainder * pow(2, i));
        i++;
    }
    return decNumber;
}

string XOR(string firstNumber, string secondNumber)
{
    string answer = "";
    int length = firstNumber.length();
    for (int i = 1; i < length; i++)
    {
        if (firstNumber[i] == secondNumber[i])
        {
            answer += '0';
        }
        else
        {
            answer += '1';
        }
    }

    return answer;
}


bool checkIsPowerOfTwo(int index)
{

    if (index == 0)
    {
        return false;
    }
    else
    {
        while (index > 1)
        {
            if (index % 2 != 0)
            {
                return false;
            }
            index = index / 2;
        }
        return true;

    }
}

vector<int> computeBinary(int number)
{
    vector<int> binary;
    while (number > 0)
    {
        int remainder= number % 2;
        number = number / 2;
        binary.push_back(remainder);    
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

        //ODD & EVEN PARITY CHECKING - ERROR DETECTING TECHNIQUES
bool evenParityChecking(string bitStream)
{

    int evenParities = 0;
    for (int i = 0; i < bitStream.length(); i++)
    {
        if (bitStream[i] == '1')
        {
            evenParities++;
        }
    }

    return evenParities % 2 == 0;

}

bool oddParityChecking(string bitStream)
{
    int oddParities = 0;
    for (int i = 0; i < bitStream.length(); i++)
    {
        if (bitStream[i] == '1')
        {
            oddParities++;
        }
    }

    return oddParities % 2 != 0;

}




            //TO COMPUTE REDUNDANT BITS FOR HAMMING CODE ALGORTIHM AT SENDER & RECEIVER SIDE
char computeRedundantBitsSender(vector<char>parityArray,int maxLengthOfArray, int position)
{
    int evenParity = 0;
    for (int index = 0; index < maxLengthOfArray;index++)
    {
        vector<int> binary = computeBinary(index);
        if (binary.capacity() >= position)
        {
            int idx = binary.capacity() - position;
            if (binary.capacity()!=0&&binary[idx] == 1)
            {
                if (parityArray[index] == '1')
                { 
                    evenParity++;
                }
            }
        }
    }

    if (evenParity % 2 == 0)
    {
        return '0';
    }
    else
    {
        return '1';
    }
}

int computeRedundantBitsReceiver(string bitStream, int maxLengthOfArray, int position)
{
    int evenParity = 0;
    for (int index = 0; index <= maxLengthOfArray; index++)
    {
        vector<int> binary = computeBinary(index);
        if (binary.capacity() >= position)
        {
            int idx = binary.capacity() - position;
            if (binary.capacity() != 0 && binary[idx] == 1)
            {
                if (bitStream[index-1] == '1')
                {
                    evenParity++;
                }
            }
        }
    }

    if (evenParity % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


                //2D PARITY BIT CHECKING


void _2DParityBitCheckingReceiver(vector<vector<int>>matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    string bitStream;
    vector<int> rowWiseErrors;
    vector<int> columnWiseErrors;


    //VERIFYING ERRORS IN ROWS
    for (int i = 0; i < rows; i++)
    {
        bitStream = "";
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0)
            {
                bitStream += '0';
            }
            else
            {
                bitStream += '1';
            }
        }

        bool parityVerified = evenParityChecking(bitStream);
        if (!parityVerified)
        {
            rowWiseErrors.push_back(i + 1);
        }
    }

    //VERIFYING ERRORS IN COLUMNS
    for (int j = 0; j < columns; j++)
    {
        bitStream = "";
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][j] == 0)
            {
                bitStream += '0';
            }
            else
            {
                bitStream += '1';
            }
        }

        bool parityVerified = evenParityChecking(bitStream);
        if (!parityVerified)
        {
            columnWiseErrors.push_back(j + 1);
        } 
    }


    if (rowWiseErrors.size() == 1 && columnWiseErrors.size() == 1)
    {
        int rowIdx = rowWiseErrors[0];
        int colIdx = columnWiseErrors[0];
        cout << "\nError Detected!\n\n";
        if (rowIdx == colIdx)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (i == rowIdx-1 && j == colIdx-1)
                    {
                        cout << "*" << " ";
                    }
                    else
                    {
                        cout << matrix[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            int _rowIdx=rowIdx;
            int _colIdx=colIdx;
            if (colIdx - 2 >= 0)
            {
                _colIdx = colIdx - 2;
            }
            if (rowIdx - 2 >= 0)
            {
                _rowIdx = rowIdx - 2;
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if ((i == rowIdx - 1 && j == _colIdx)||(i==_rowIdx&&j==colIdx))
                    {
                        cout << "* ";
                    }
                    else
                    {
                        cout << matrix[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }

    }
    else if (rowWiseErrors.size() == 0 && columnWiseErrors.size() > 0)
    {
        cout << "\nError Detected!\n\n";
        int index = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if ((index<columnWiseErrors.size())&&(i == 0 && (j == columnWiseErrors[index]-1)))
                {
                    index++;
                    cout << "* ";
                }
                else
                {
                    cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    else if (columnWiseErrors.empty() && rowWiseErrors.empty())
    {
        cout << "\nError Cannot Be Detected!\n";
    }
    else
    {
        if (rowWiseErrors.size() == 1 && columnWiseErrors.size() > 1)
        {
            cout << "\nError Detected!\n\n";
            int idx = 0;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    if (idx<columnWiseErrors.size()&&i == rowWiseErrors[0]-1 && j == columnWiseErrors[idx]-1)
                    {
                        cout << "* ";
                        idx++;
                    }
                    else
                    {
                        cout << matrix[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            if (rowWiseErrors.size() == columnWiseErrors.size())
            {
                cout << "\nError Detected!\n\n";
                int idx = 0;
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < columns; j++)
                    {
                        if (idx<rowWiseErrors.size()&&i == rowWiseErrors[idx] - 1 && j == columnWiseErrors[idx] - 1)
                        {
                            cout << "* ";
                            idx++;
                        }
                        else
                        {
                            cout << matrix[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "\nError Cannot Be Detected!\n";
            }
        }
    }

    cout << "\n\n\t\t=================================================================================\n\n";

}


void _2DParityBitCheckingSender(vector<vector<int>>matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    int evenParityRow;
    int evenParityColumn;

    for (int i = 0; i < rows-1; i++)
    {
        evenParityRow = 0;

        for (int j = 0; j < columns-1; j++)
        {
            if (matrix[i][j] == 1)
            {
                evenParityRow++;
            }
        }

        if (evenParityRow % 2 == 0)
        {
            matrix[i][columns-1] = 0;
        }
        else
        {
            matrix[i][columns-1] = 1;
        }
    }

    for (int j = 0; j < columns; j++)
    {
        evenParityColumn = 0;
        for (int i = 0; i < rows-1; i++)
        {
            if (matrix[i][j] == 1)
            {
                evenParityColumn++;
            }
        }

        if (evenParityColumn % 2 == 0)
        {
            matrix[rows-1][j] = 0;
        }
        else
        {
            matrix[rows-1][j] = 1;
        }
    }

    cout << "\nMessage to be Transmitted: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j];
        }
        cout <<" ";
    }
    cout << endl;
}


                //HAMING CODE ALGORITHM - ERROR DETECTION TECHNIQUE
int hamingCodeAlgorithmReceiver(string bitStream)
{

    vector<int> positionOfRedundantBits;
    vector<int> decodedBits;
    int size = bitStream.length();
    for (int i = 0; i < size; i++)
    {
        if (checkIsPowerOfTwo(i))
        {
            positionOfRedundantBits.push_back(i);
        }
    }

    
    for (int i = 0; i < positionOfRedundantBits.capacity(); i++)
    {
        int redundantBit = computeRedundantBitsReceiver(bitStream, size, i + 1);
        decodedBits.push_back(redundantBit);
    }


    int position = 0;
    int k = 0;
    for (int i = 0; i < decodedBits.capacity(); i++)
    {
        position = position + (decodedBits[i] * pow(2, k));
        k++;
    }

    cout << endl;
    return position;
}

void hamingCodeAlgorithmSender(string bitStream)
{
    int leftSide, rightSide, r;
    int m = bitStream.length();

    for (r = 1;; r++)
    {
        leftSide = pow(2, r);
        rightSide = m + r + 1;

        if (leftSide >= rightSide)
        {
            break;
        }
    }

    int size = m + r + 1;
    int idx = 0;
    vector<char> parityArray(size);
    vector<int> positionOfRedundantBits;
    for (int i = 0; i < size; i++)
    {
        if (!checkIsPowerOfTwo(i)&&i!=0)
        {
            parityArray[i] = bitStream[idx];
            idx++;
        }
        else if(i!=0)
        {
            positionOfRedundantBits.push_back(i);
        }
    }

    for (int i = 0; i < positionOfRedundantBits.capacity(); i++)
    {
        idx = positionOfRedundantBits[i];
        char redundantBit = computeRedundantBitsSender(parityArray, size, i+1);
        parityArray[idx] = redundantBit;
    }


    cout << "\nMessage to be Transmitted ";
    for (int i = 1; i < parityArray.capacity(); i++)
    {
        cout << parityArray[i];
    }

}


            //CYCLIC REDUNDANCY CHECK - ERROR DETECTING TECHNIQUE
void cyclicRedundancyCheckSender(string bitStream,string divisor)
{
    string chunkOfBits = bitStream.substr(0, divisor.length());
    int lenOfChunk = chunkOfBits.length();
    int lenOfDivisor = divisor.length();
    int idx = lenOfDivisor;
    string answer;

    while (lenOfChunk >= lenOfDivisor)
    {
        if (chunkOfBits[0] == '0')
        {
            string partialQuotient(lenOfDivisor, '0');
            answer=XOR(chunkOfBits, partialQuotient);
            if (idx < bitStream.length())
            {
                chunkOfBits = answer + bitStream[idx];
                lenOfChunk = chunkOfBits.length();
                idx++;
            }
            else
            {
                chunkOfBits = answer;
                lenOfChunk = chunkOfBits.length();
            }
        }
        else
        {
            answer = XOR(chunkOfBits, divisor);
            if (idx < bitStream.length())
            {
                chunkOfBits = answer + bitStream[idx];
                lenOfChunk = chunkOfBits.length();
                idx++;
            }
            else
            {
                chunkOfBits = answer;
                lenOfChunk = chunkOfBits.length();
            }
        }
    }

    string tempMessage = bitStream.substr(0, bitStream.length() - (lenOfDivisor - 1));
    string message = tempMessage + answer;
    cout << "\nMessage to be Transmitted: " << message << endl;
}


void cyclicRedundancyCheckReceiver(string bitStream,string divisor)
{
    string chunkOfBits = bitStream.substr(0, divisor.length());
    int lenOfChunk = chunkOfBits.length();
    int lenOfDivisor = divisor.length();
    int idx = lenOfDivisor;
    string answer;

    while (lenOfChunk >= lenOfDivisor)
    {
        if (chunkOfBits[0] == '0')
        {
            string partialQuotient(lenOfDivisor, '0');
            answer = XOR(chunkOfBits, partialQuotient);
            if (idx < bitStream.length())
            {
                chunkOfBits = answer + bitStream[idx];
                lenOfChunk = chunkOfBits.length();
                idx++;
            }
            else
            {
                chunkOfBits = answer;
                lenOfChunk = chunkOfBits.length();
            }
        }
        else
        {
            answer = XOR(chunkOfBits, divisor);
            if (idx < bitStream.length())
            {
                chunkOfBits = answer + bitStream[idx];
                lenOfChunk = chunkOfBits.length();
                idx++;
            }
            else
            {
                chunkOfBits = answer;
                lenOfChunk = chunkOfBits.length();
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == '1')
        {
            flag = false;
            break;
        }
    }

    if (!flag)
    {
        cout << "\nError Detected!\n";
    }
    else
    {
        cout << "\nNo Error Detected!\n";
    }
}


        //CHECKSUM - ERROR DETECTING TECHNIQUE
void checkSumReceiver(string bitStream)
{
    int chunkOfBits;
    int size = bitStream.length();
    vector<int>decimalNumbers;
    for (int i = 0; i < size;)
    {
        chunkOfBits = 0;
        for (int j = 0; j < 8; j++)
        {
            int number = bitStream[i] - '0';
            chunkOfBits = chunkOfBits + (number * pow(10, 8 - j - 1));
            i++;
        }


        int decNum = computeDecimal(chunkOfBits);
        decimalNumbers.push_back(decNum);
    }

    int sum = 0;
    for (int i = 0; i < decimalNumbers.size(); i++)
    {
        sum += decimalNumbers[i];
    }

    vector<int> checksum = computeBinary(sum);
    int length = checksum.size() - 8;
    int leftMostRedundantBitNumber = 0;
    int rightMostNumber = 0;
    for (int i = 0; i < length; i++)
    {
        leftMostRedundantBitNumber = leftMostRedundantBitNumber + (checksum[i] * pow(10, length - i - 1));
    }
    int k = 0;
    for (int i = length; i < checksum.size(); i++)
    {
        rightMostNumber = rightMostNumber + (checksum[i] * pow(10, 8 - k - 1));
        k++;
    }

    int decLeftMostRedundantBitNumber = computeDecimal(leftMostRedundantBitNumber);
    int decRightMostNumber = computeDecimal(rightMostNumber);

    int wrappedChecksum = decLeftMostRedundantBitNumber + decRightMostNumber;
    vector<int> finalChecksum = computeBinary(wrappedChecksum);


    bool flag = true;
    for (int i = 0; i < finalChecksum.size(); i++)
    {
        if (finalChecksum[i] == 0)
        {
            flag = false;
            break;
        }
    }

    if (!flag)
    {
        cout << "\nError Detected!\n";
        for (int i = 0; i < bitStream.length(); )
        {
            for (int j = 0; j < 8; j++)
            {
                cout << bitStream[i];
                i++;
            }
            cout << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "\nNo error Detected!\n";
    }
}

void checkSumSender(string bitStream)
{
    int chunkOfBits;
    int size = bitStream.length();
    vector<int>decimalNumbers;
    for (int i = 0; i < size;)
    {
        chunkOfBits = 0;
        for (int j = 0; j < 8; j++)
        {
            int number = bitStream[i] - '0';
            chunkOfBits = chunkOfBits + (number * pow(10, 8 - j - 1));
            i++;
        }


        int decNum = computeDecimal(chunkOfBits);
        decimalNumbers.push_back(decNum);
    }
        int sum = 0;
        for (int i = 0; i < decimalNumbers.size(); i++)
        {
            sum += decimalNumbers[i];
        }

        vector<int> checksum = computeBinary(sum);
        int length = checksum.size() - 8;
        int leftMostRedundantBitNumber = 0;
        int rightMostNumber=0;
        for(int i=0;i<length;i++)
        {
             leftMostRedundantBitNumber = leftMostRedundantBitNumber + (checksum[i] * pow(10, length - i - 1));
        }
        int k = 0;
        for (int i = length; i < checksum.size(); i++)
        {
            rightMostNumber = rightMostNumber + (checksum[i] * pow(10, 8 - k - 1));
            k++;
        }

        int decLeftMostRedundantBitNumber = computeDecimal(leftMostRedundantBitNumber);
        int decRightMostNumber = computeDecimal(rightMostNumber);

        int wrappedChecksum = decLeftMostRedundantBitNumber + decRightMostNumber;
        vector<int> finalChecksum = computeBinary(wrappedChecksum);
        if (finalChecksum.size() < 8)
        {
            int _index=finalChecksum.size()-1;
            int _size = 8 - finalChecksum.size();
            finalChecksum.resize(8);
            for (int i = finalChecksum.size()-1;i>=_size;i--)
            {
                finalChecksum[i] = finalChecksum[_index];
                _index--;
            }

            for (int i = 0; i < _size; i++)
            {
                finalChecksum[i] = 0;
            }    
        }
       cout << "\nMessage to be Transmitted: ";
        for (int i = 0; i < bitStream.length(); )
        {
            for (int j = 0; j < 8; j++)
            {
                cout << bitStream[i];
                i++;
            }
            cout << " ";
        }
        for (int i = 0; i < finalChecksum.size(); i++)
        {
            if (finalChecksum[i] == 1)
            {
                cout<<0;
            }
            else
            {
                cout<<1;
            }
        }
        cout << endl;
}


int main()
{

    cout << "\n\t\t=================================================================================\n";
    cout << "\t\t\t\t\tERROR CONTROL MECHANISMS\n";
    cout << "\n\t\t=================================================================================\n";
    int choice;

    while (true)
    {
        cout << "\n1.Parity Bit Checking\n";
        cout << "2. 2D Parity Bit Checking(Sender Side)\n";
        cout << "3. 2D Parity Bit Checking(Receiver Side)\n";
        cout << "4. Haming Code Algorithm(Sender Side)\n";
        cout << "5. Haming Code Algorithm(Receiver Side)\n";
        cout << "6. Cyclic Redundancy Check(Sender Side)\n";
        cout << "7. Cyclic Redundancy Check(Receiver Side)\n";
        cout << "8. CheckSum(Sender Side)\n";
        cout << "9. CheckSum(Receiver Side)\n";
        cout << "-1. To Quit\n";
        cout << "\n\n\t\t=================================================================================\n\n";
        cout << "Your Choice Here: ";
        cin >> choice;


        if (choice == -1)
        {
            break;
        }
        else if (choice == 1)
        {
            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tPARITY BIT CHECKING\n";
            cout << "\n\t\t=================================================================================\n";

            char choiceOfParity;
            string bitStream;
            
            cout << "Parity Types:- \n";
            cout << "E: For Even Parity\n";
            cout << "O: For Odd Parity\n";
            cout << "==================\n\n";
            cout << "Your Choice Here: ";
            cin >> choiceOfParity;

            if ((choiceOfParity == 'E' || choiceOfParity == 'O') || (choiceOfParity == 'e' || choiceOfParity == 'o'))
            {
                while (true)
                {
                    bool flag = true;
                    cout << "Bit Stream: ";
                    cin >> bitStream;
                    for (int i = 0; i < bitStream.length(); i++)
                    {
                        if (bitStream[i] != '0' && bitStream[i] != '1')
                        {
                            cout << "Invalid Bit Stream!\n";
                            cout << "Try Again\n";
                            flag = false;
                            break;
                        }
                    }

                    if (flag != false)
                    {
                        break;
                    }
                }

                if (choiceOfParity == 'E' || choiceOfParity == 'e')
                {
                    bool answer = evenParityChecking(bitStream);
                    if (!answer)
                    {
                        cout << "\nBit Stream(" << bitStream << ") doesn't satisfy Even Parity!\n";
                    }
                    else
                    {
                        cout << "\nBit Stream("<<bitStream << ") satisfies Even Parity!\n";
                    }
                }
                else
                {
                    bool answer = oddParityChecking(bitStream);
                    if (!answer)
                    {
                        cout << "\nBit Stream(" << bitStream << ") doesn't satisfy Odd Parity!\n";
                    }
                    else
                    {
                        cout << "\nBit Stream("<<bitStream << ") satisfies Odd Parity!\n";
                    }
                }
            }
            else
            {

                cout << "Invalid Choice!\n";
            }

            cout << "\n\n\t\t=================================================================================\n\n";

        }


        else if (choice == 2)
        {

            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\t2D-PARITY BIT CHECKING(Sender Side)\n";
            cout << "\n\t\t=================================================================================\n";
            int rows, columns;

            while (true)
            {
                cout << "\nRows: ";
                cin >> rows;
                if (rows <= 0)
                {
                    cout << "Invalid Number of Rows!\n";
                    cout << "Try Again!\n";
                }
                else
                {
                    break;
                }
            }

            while (true)
            {
                cout << "Columns: ";
                cin >> columns;
                if (columns <= 0)
                {
                    cout << "Invalid Number of Columns!\n";
                    cout << "Try Again!\n";
                }
                else
                {
                    break;
                }
            }

            vector<vector<int>> matrix(rows + 1, vector<int>(columns + 1));
            int bit;
            cout << "Bit Stream:- \n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    cin >> bit;
                    while (!isValidBit(bit))
                    {
                        cout << "Invalid bit value!\n Please enter 0 or 1: ";
                        cin >> bit;
                    }
                    matrix[i][j] = bit;
                }
            }

            _2DParityBitCheckingSender(matrix);
            cout << "\n\n\t\t=================================================================================\n\n";


        }
        else if (choice == 3)
        {
            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\t2D-PARITY BIT CHECKING(Receiver Side)\n";
            cout << "\n\t\t=================================================================================\n";
            int rows, columns;


            while (true)
            {
                cout << "\nRows: ";
                cin >> rows;
                if (rows <= 0)
                {
                    cout << "Invalid Number of Rows!\n";
                    cout << "Try Again!\n";
                }
                else
                {
                    break;
                }
            }

            while (true)
            {
                cout << "Columns: ";
                cin >> columns;
                if (columns <= 0)
                {
                    cout << "Invalid Number of Columns!\n";
                    cout << "Try Again!\n";
                }
                else
                {
                    break;
                }
            }

            vector<vector<int>> matrix(rows, vector<int>(columns));
            int bit;
            cout << "Bit Stream:- \n";
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {

                    cin >> bit;
                    while (!isValidBit(bit))
                    {
                        cout << "Invalid bit value!\n Please enter 0 or 1: ";
                        cin >> bit;
                    }
                    matrix[i][j] = bit;
                }
            }

            _2DParityBitCheckingReceiver(matrix);
            cout << "\n\n\t\t=================================================================================\n\n";


        }
        else if (choice == 4)
        {

            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tHAMING CODE ALGORITHM(Sender Side)\n";
            cout << "\n\t\t=================================================================================\n";
            string bitStream;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
            hamingCodeAlgorithmSender(bitStream);
            cout << "\n\n\t\t=================================================================================\n\n";


        }

        else if (choice == 5)
        {
            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tHAMING CODE ALGORITHM(Receiver Side)\n";
            cout << "\n\t\t=================================================================================\n";
            string bitStream;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
            int position = hamingCodeAlgorithmReceiver(bitStream);
            cout << "\nError Detected at Position " << position << endl;
            cout << "\n\n\t\t=================================================================================\n\n";

        }

        else if (choice == 6)
        {


            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tCYCLIC REDUNDANCY CHECK(Sender Side)\n";
            cout << "\n\t\t=================================================================================\n";

            string bitStream;
            string divisor;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }

            while (true)
            {
                bool flag = true;
                cout << "Divisor: ";
                cin >> divisor;

                for (int i = 0; i < divisor.length(); i++)
                {
                    if (divisor[i] != '0' && divisor[i] != '1')
                    {
                        cout << "Invalid Divisor!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
            string tempStr(divisor.length() - 1, '0');
            bitStream = bitStream + tempStr;
            cyclicRedundancyCheckSender(bitStream, divisor);
            cout << "\n\n\t\t=================================================================================\n\n";

        }
        else if (choice == 7)
        {
            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tCYCLIC REDUNDANCY CHECK(Receiver Side)\n";
            cout << "\n\t\t=================================================================================\n";

            string bitStream;
            string divisor;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }

            while (true)
            {
                bool flag = true;
                cout << "Divisor: ";
                cin >> divisor;

                for (int i = 0; i < divisor.length(); i++)
                {
                    if (divisor[i] != '0' && divisor[i] != '1')
                    {
                        cout << "Invalid Divisor!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
            cyclicRedundancyCheckReceiver(bitStream, divisor);
            cout << "\n\n\t\t=================================================================================\n\n";

        }
        else if (choice == 8)
        {

            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tCHECKSUM-ERROR DETECTING TECHNIQUE(Sender Side)\n";
            cout << "\n\t\t=================================================================================\n";
            string bitStream;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }

            if (bitStream.length() % 8 != 0)
            {
                string tempBitStream = "";
                int remainder = bitStream.length() % 8;
                int bitsToBeAppended = 8 - remainder;
                for (int i = 0; i < bitsToBeAppended; i++)
                {
                    tempBitStream += '0';
                }
                tempBitStream = tempBitStream + bitStream;
                bitStream = tempBitStream;
            }

            checkSumSender(bitStream);
            cout << "\n\n\t\t=================================================================================\n\n";

        }

        else if (choice == 9)
        {

            cout << "\n\t\t=================================================================================\n";
            cout << "\t\t\t\t\tCHECKSUM-ERROR DETECTING TECHNIQUE(Receiver Side)\n";
            cout << "\n\t\t=================================================================================\n";
            string bitStream;
            while (true)
            {
                bool flag = true;
                cout << "\nBit Stream: ";
                cin >> bitStream;

                for (int i = 0; i < bitStream.length(); i++)
                {
                    if (bitStream[i] != '0' && bitStream[i] != '1')
                    {
                        cout << "Invalid Bit Stream!\n";
                        cout << "Try Again\n";
                        flag = false;

                        break;
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }

            checkSumReceiver(bitStream);
            cout << "\n\n\t\t=================================================================================\n\n";
        }
        else
        {
            cout << "Invalid Choice!\n";;
        }
    }
}