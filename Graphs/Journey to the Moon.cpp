#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
const int N=1e5+10;
vector<int> parent(N);
vector<int> siz(N);
void make(int item)
{
    parent[item]=item;
    siz[item]=1;
}
int find(int a)
{
    if(parent[a]==a)
        return parent[a];
    else
    {
        parent[a]=find(parent[a]);
        return parent[a];
    }
}
void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    else
    {
        if(siz[a]>siz[b])
        {
            parent[b]=a;
            siz[a]+=siz[b];
        }
        else
        {
            parent[a]=b;
            siz[b]+=siz[a];
        }
    }
}
int journeyToMoon(int n, vector<vector<int>> astronaut)
{
     for(int i=0;i<n;i++)
    {
        make(i);
    }
    for(int i=0;i<astronaut.size();i++)
    {
        Union(astronaut[i][0],astronaut[i][1]);
    }
    map<long long,long long> mp;
    for(int i=0;i<n;i++)
    {
        mp[find(i)]++;
    }
    long long temp=(n*(n-1))/2;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        temp=temp-(it->second)*(it->second-1)/2;
    }
return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
