// Online C++ compiler to run C++ program online
#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

// Hash function wrapper
size_t hashFunction(const string &key)
{
    return hash<string>{}(key);
}

class ConsistentHashRing
{
private:
    int virtualNodes;
    map<size_t, string> ring;

public:
    ConsistentHashRing(int vNodes = 3) : virtualNodes(vNodes) {}

    void addServer(const string &serverName)
    {
        for (int i = 0; i < virtualNodes; i++)
        {
            ostringstream oss;
            oss << serverName << "#VN" << i;
            size_t hash = hashFunction(oss.str());
            ring[hash] = serverName;
            cout << "Added virtual node: " << oss.str() << " (hash=" << hash << ")\n";
        }
    }

    void removeServer(const string &serverName)
    {
        for (int i = 0; i < virtualNodes; i++)
        {
            ostringstream oss;
            oss << serverName << "#VN" << i;
            size_t hash = hashFunction(oss.str());
            ring.erase(hash);
            cout << "Removed virtual node: " << oss.str() << " (hash=" << hash << ")\n";
        }
    }

    string getServerForKey(const string &key)
    {
        if (ring.empty())
            return "No servers available";

        size_t hash = hashFunction(key);
        auto it = ring.lower_bound(hash);

        if (it == ring.end())
            return ring.begin()->second; // Wrap around the ring
        return it->second;
    }

    void printRing()
    {
        cout << "\nCurrent Hash Ring:\n";
        for (const auto &entry : ring)
            cout << "Hash: " << entry.first << " → Server: " << entry.second << "\n";
    }
};

int main()
{
    ConsistentHashRing ring(3); // 3 virtual nodes per server

    ring.addServer("ServerA");
    ring.addServer("ServerB");
    ring.addServer("ServerC");

    ring.printRing();

    vector<string> keys = {"User1", "User2", "User3", "User4", "User5"};
    cout << "\nKey → Server Mapping:\n";
    for (auto &key : keys)
        cout << key << " → " << ring.getServerForKey(key) << "\n";

    cout << "\nRemoving ServerB...\n";
    ring.removeServer("ServerB");

    cout << "\nKey → Server Mapping after removal:\n";
    for (const auto &key : keys)
        std::cout << key << " → " << ring.getServerForKey(key) << "\n";

    return 0;
}