#include "Nettverk.h"

void Network::addEdge(string u, string v){
    if (!symmetric){
        edges[u].insert(v);
    }else{
        edges[u].insert(v);
        edges[v].insert(u);
    }
}

Network loadNetwork(string filename, bool symmetric){
    ifstream ist{filename};
    if(!ist){
        throw string("Could not open file " + filename); 
    }
    Network airports;
    string line;
    while (getline(ist,line)){
        stringstream ss{line};
        string node;
        ss >> node;
        airports.addNode(node);
        string edge;
        while (ss >> edge){
            airports.addEdge(node, edge);
        }
    }
    return airports;
}
 
void Network::addPath(vector<string> nodes){
    if (nodes.size() <= 1){return;}
    for (unsigned int i=0; i<nodes.size()-1; ++i){
        addEdge(nodes[i],nodes[i+1]);
    }
}

Network Network::operator+(Network &rhs){
    Network added;
    added.edges = rhs.edges;
    added.nodes = rhs.nodes;
    for (string p : nodes){
        added.addNode(p);
    }
    for (auto p : edges){
        for (auto edge : p.second){
            added.addEdge(p.first, edge);
        } 
    }
    return added;
}

map<string, int> Network::traverse(string start){
    map<string,int> dist;
    queue<string> q;
    q.push(start);
    dist[start] = 0;
    while (q.size() > 0){
        string current = q.front();
        q.pop();
        for (auto p : edges[current]){
            if (dist.find(p) == dist.end()){
                dist[p] = dist[current] + 1;
                q.push(p);
            }
        }
    }
    return dist;
}

int Network::distance(string from, string to){
    map<string,int> nodesDistances = traverse(from);
    if (nodesDistances.find(to) != nodesDistances.end()){
        return nodesDistances[to];
    }else{
        return -1;
    }
}

float Network::avgPathLength() {
    float sumSoFar = 0;  
    float N = static_cast<float>(nodes.size());
    for (string n : nodes) {
        map<string, int> dist = traverse(n);
            for (pair<string, int> p : dist){
                sumSoFar += p.second;
            }
    }
    return sumSoFar / (N * (N - 1));
}