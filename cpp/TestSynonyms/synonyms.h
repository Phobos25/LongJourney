#pragma once

#include <map>
#include <set>
#include <string>
using namespace std;


// Interface

using Synonyms = map<string, set<string>>;
void AddSynonyms(Synonyms& synonyms, 
        const string& first_word, const string& second_word);

size_t GetSynonymCount( Synonyms& synonyms, 
                        const string& first_word);

bool AreSynonyms(Synonyms& synonyms,
        const string& first_word, const string& second_word);