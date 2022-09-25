#include <iostream>

using namespace std;

typedef struct
{
    int row;
    int col;
} position;

char matrix[5][5]; // Global Variable

void generateMatrix(string key)
{
    /* flag keeps track of letters that are filled in matrix */
    /* flag = 0 -> letter not already present in matrix */
    /* flag = 1 -> letter already present in matrix */
    int flag[26] = {0}, x = 0, y = 0;

    /* Add all characters present in the key */
    for(int i = 0; i < key.length(); i++)
    {
        if(key[i] == 'j') key[i] = 'i'; // replace j with i

        if(flag[key[i] - 'a'] == 0)
        {
            matrix[x][y++] = key[i];
            flag[key[i] - 'a'] = 1;
        }
        if(y == 5) x++, y = 0;
    }

    /* Add remaining characters */
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        if(ch == 'j') continue; // don't fill j since j was replaced by i

        if(flag[ch - 'a'] == 0)
        {
            matrix[x][y++] = ch;
            flag[ch - 'a'] = 1 ;
        }
        if(y == 5) x++, y = 0;
    }
}

/* function to add filler letter('x') */
string formatMessage(string msg)
{
    /* for(int i = 0; i < msg.length(); i++) */
    /* { */
    /* 	if(msg[i] == 'j')  msg[i] = 'i'; */
    /* } */
    for (char &c: msg)
    {
        if (c=='j') c='i';
    }

    for(int i = 1; i < msg.length(); i += 2) //pairing two characters
    {
        if(msg[i - 1] == msg[i])  msg.insert(i, "x");
    }

    if(msg.length() % 2 != 0)  msg += "z";
    return msg;
}

/* Returns the position of the character */
position getPosition(char c)
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(c == matrix[i][j])
            {
                position p = {i, j};
                return p;
            }
}

string en_decrypt(string message, int ch)
{
    string ctext = "";
    for(int i = 0; i < message.length(); i += 2) // i is incremented by 2 inorder to check for pair values
    {
        position p1 = getPosition(message[i]);
        position p2 = getPosition(message[i + 1]);
        int x1 = p1.row, y1 = p1.col, x2 = p2.row, y2 = p2.col;

        if( x1 == x2 ) // same row
        {
            if (ch==0)
                ctext = ctext + matrix[x1][(y1 + 1) % 5] +  matrix[x2][(y2 + 1) % 5];
            else
                ctext = ctext + matrix[x1][ --y1 < 0 ? 4 : y1 ] + matrix[x2][ --y2 < 0 ? 4 : y2 ];
        }
        else if( y1 == y2 ) // same column
        {
            if (ch==0)
                ctext = ctext + matrix[ (x1 + 1) % 5 ][ y1 ] + matrix[ (x2 + 1) % 5 ][ y2 ];
            else
                ctext = ctext + matrix[ --x1 < 0 ? 4 : x1 ][y1] + matrix[ --x2 < 0 ? 4 : x2 ][y2];

        }
        else
        {
            ctext = ctext + matrix[ x1 ][ y2 ] + matrix[ x2 ][ y1 ];
        }
    }
    return ctext;
}

int main()
{
    string plaintext;
    cout << "Enter message : ";
    cin >> plaintext;

    string key;
    cout << "\nEnter key: ";
    cin >> key;

    generateMatrix(key);

    cout <<" Matrix:" << endl;
    for(int k = 0; k < 5; k++)
    {
        for(int j = 0; j < 5; j++)
            cout << matrix[k][j] << "  ";
        cout << endl;
    }

    cout << "Actual Message \t\t: " << plaintext << endl;
    string fmsg = formatMessage(plaintext);
    cout << "Formatted Message \t: " << fmsg << endl;
    string ciphertext = en_decrypt(fmsg, 0);
    cout << "Encrypted Message \t: " << ciphertext << endl;
    string decryptmsg = en_decrypt(ciphertext, 1);
    cout << "Decrypted Message \t: " << decryptmsg << endl;

}
