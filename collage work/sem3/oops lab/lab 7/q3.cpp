// Define a class ResourceManager with a private int* resource. Implement a constructor 
// that allocates memory for resource and sets it to a value (e.g., 200). Add a method int* 
// getResource() that returns the pointer. Add a destructor that deallocates resource. 
// In main(), create an instance of ResourceManager, get the resource pointer, print its 
// value, then let the object go out of scope (causing destructor to run), and attempt to 
// access the pointer afterward.

#include<bits/stdc++.h>
using namespace std;

class ResourceManager {
    int* resource;
public:
    ResourceManager() {
        resource = new int(200);
    }
    int* getResource() {
        return resource;
    }
    ~ResourceManager() {
        delete resource;
    }
};

int main() {
    ResourceManager resMgr;
    int* resPtr = resMgr.getResource();
    cout << "Resource value: " << *resPtr << endl;
    return 0;
}
