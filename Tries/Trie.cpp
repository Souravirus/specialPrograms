#include<iostream>
#include<map>
#include<fstream>
class Trie
{
private:

    struct TrieTree
    {
        std::map<char,struct TrieTree*> map_child;
        std::map<char,unsigned long> map_count;
        bool _isWord=false;
    };

    struct TrieTree* _root=NULL;
    unsigned long _wordCount=0;
    unsigned long _INITIALIZE=1;

    struct TrieTree* getNode()
    {
        return new TrieTree;
    };


    void printWords(struct TrieTree* Tptr,std::string pre)
    {
        if(Tptr->_isWord==true)
        {
            std::cout<<pre<<" ";

        }

        std::map<char,struct TrieTree*>::iterator it;
        it=Tptr->map_child.begin();
        while(it!=Tptr->map_child.end())
        {
        //    std::cout<<"call ";
            pre.push_back(it->first);
            printWords(it->second,pre);
            pre.erase(pre.length()-1);  //erase last prefix character
            it++;
        }

    }


public:

    Trie()
    {
        _root=getNode();
    }
    unsigned long WordCount()
    {
        return _wordCount;
    }
    unsigned long WordCount(std::string pre) //count words with prefix pre
    {
        if(WordCount()!=0)
        {
            struct TrieTree *Tptr=_root;
            std::map<char,unsigned long>::iterator it;
            char lastChar;
            for(int i=0;i<pre.length()-1;i++)
            {
                Tptr=Tptr->map_child[pre[i]];
            }
            lastChar=pre[pre.length()-1];
            it=Tptr->map_count.find(lastChar);
            if(it!=Tptr->map_count.end())
            {
                return Tptr->map_count[lastChar];
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }

    unsigned long Insert(std::string key)   //return word count after insertion
    {
        struct TrieTree *Tptr =_root;
        std::map<char,struct TrieTree*>::iterator it;

        if(!SearchWord(key))
        {
            for(int level=0;level<key.length();level++)
            {
                it=Tptr->map_child.find(key[level]);
                if(it==Tptr->map_child.end())
                {
                    //alphabet does not exist in map
                    Tptr->map_child[key[level]]=getNode();  // new node with value pointing to it
                    Tptr->map_count[key[level]] = _INITIALIZE;
                    Tptr=Tptr->map_child[key[level]];       //assign pointer to newly obtained node
                    if(level==key.length()-1)
                        Tptr->_isWord=true;
                }
                else
                {   //alphabet exists at this level
                    Tptr->map_count[key[level]]++;
                    Tptr=Tptr->map_child[key[level]];
                    if(level==key.length()-1)
                        Tptr->_isWord=true;
                }
            }
            _wordCount++;
        }
        return _wordCount;
    }

    bool SearchWord(std::string key)
    {
        struct TrieTree *Tptr =_root;
        std::map<char,struct TrieTree*>::iterator it;
        for(int level=0;level<key.length();level++)
        {
            it=Tptr->map_child.find(key[level]);
         //   cout<<" "<<Tptr->map_child.size()<<endl;  //test to count entries at each map level

            if(it!=Tptr->map_child.end())
            {
                Tptr=Tptr->map_child[key[level]];
            }
            else
            {
                return false;
            }
        }
        if(Tptr->_isWord==true)
            return true;
        return false;
    }

    void PrintAllWords()
    {   //print all words in trie in dictionary order
        struct TrieTree *Tptr =_root;
        if(Tptr->map_child.empty())
            {
                std::cout<<"Trie is Empty"<<std::endl;
                return;
            }

        printWords(Tptr,"");

    }
    void PrintAllWords(std::string pre)
    {   //print all words in trie with prefix pre in Dictionary order
        struct TrieTree *Tptr =_root;
        if(Tptr->map_child.empty())
            {
                std::cout<<"Trie is Empty"<<std::endl;
                return;
            }

        for(int i=0;i<pre.length();i++)
        {
            Tptr=Tptr->map_child[pre[i]];
        }

        printWords(Tptr,pre);

    }


};
int main(){
Trie t;
std::string str;
std::fstream fs;
fs.open("words.txt",std::ios::in);

while(fs>>str){
    t.Insert(str);
}
std::cout<<t.WordCount();
t.PrintAllWords();

return 0;
}
