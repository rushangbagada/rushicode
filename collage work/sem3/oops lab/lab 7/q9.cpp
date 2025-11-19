// Dangling Pointer with File Buffer 
// Create a class FileBuffer that: 
// • Dynamically allocates a buffer (char* buf) for file content. 
// • Reads data from a text file into the buffer. 
// • Provides a char* getBuffer() method. 
// • Destructor should delete[] buf. 
// In main(): 
//   - Create a FileBuffer object, read data, get the buffer pointer, print it. 
// - After the object goes out of scope, try to print the buffer again (dangling pointer). 
// - Modify the program to copy the buffer before object destruction to solve dangling  
//       pointer. 
// (Concepts: dangling pointer, destructor behavior, safe memory ownership)


#include <bits/stdc++.h>
using namespace std;

class
FileBuffer {
    char* buf;
    size_t size;
public:
    FileBuffer(const string& filename) {
        ifstream file(filename, ios::binary | ios::ate);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            buf = nullptr;
            size = 0;
            return;
        }
        size = file.tellg();
        file.seekg(0, ios::beg);
        buf = new char[size + 1]; 
        file.read(buf, size);
        buf[size] = '\0'; 
    }

    char* getBuffer() {
        return buf;
    }

    ~FileBuffer() {
        delete[] buf;
    }
};

int main() {
    FileBuffer fileBuffer("example.txt");

    
    char* buffer = fileBuffer.getBuffer();

   
    if (buffer) {
        cout << "File content:\n" << buffer << endl;
    }

 
    cout << "Trying to access buffer after object destruction:\n" << buffer << endl;

    return 0;
}