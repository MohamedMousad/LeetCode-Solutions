class Solution {
public:
    vector<int> get_versions(string& version){
        vector<int> revisions;
        for (int i = 0 ; i < version.size() ; i++){
            string revision;
            while ( i < version.size() && version[i] == '0') i++;
            while( i < version.size() && version[i] && version[i] != '.') revision.push_back(version[i]) , i++;
            revisions.push_back((revision.size() > 0 ? stoi(revision) : 0));
        }
        return revisions;
    }
    int compareVersion(string version1, string version2) {
        auto first = get_versions(version1) , second = get_versions(version2);
        for (int i = 0 ; i < min(first.size() , second.size()) ; i++){
            if ( first[i] < second[i] ) return -1;
            else if ( first[i] > second[i] ) return 1;
        }
        for (int i = min(first.size() , second.size()) ; i < max(first.size() , second.size()) ; i++){
            if ( i < first.size() && first[i] > 0 ) return 1;
            else if ( i < second.size() && second[i] > 0  ) return -1;
        }
        return 0;
    }
};