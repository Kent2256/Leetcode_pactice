Given a text file file.txt, transpose its content.

You may assume that each row has the same number of columns, and each field is separated by the ' ' character.

Example:

If file.txt has the following content:

name age
alice 21
ryan 30
Output the following:

name alice ryan
age 21 30

int main(){
    string filename="file.txt";
    ifstream input_stream(filename);
    string line;
    while(getline(input_stream,line)){
        cout << line << endl;
    }
    return 0;
}