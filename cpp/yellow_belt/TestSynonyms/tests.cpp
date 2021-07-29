#include "tests.h"


void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty,"a", "b");
        const Synonyms expected = {
            {"a", {  "b"}},
            {"b", {  "a"}},
            };
        AssertEqual(empty, expected,"Addto  empty");
    }
    {
        Synonyms synonyms = {
            {"a", {  "b"}},
            {"b", {  "a", "c"}},
            {"c", {  "b"}}
        };
        AddSynonyms(synonyms,"a", "c");
        const Synonyms expected = {
            {"a", {  "b", "c"}},
            {"b", {  "a", "c"}},
            {"c", {  "b", "a"}}
        };
        AssertEqual(synonyms, expected,"Nonempty");
    }
}

void TestCount(){
    {
        Synonyms empty;
        AssertEqual(GetSynonymCount(empty, "a"), 0u, "Synonym empty");
    }
    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        AssertEqual(GetSynonymCount(synonyms, "a"), 2u, "Number of synonyms 2");
        AssertEqual(GetSynonymCount(synonyms, "b"), 1u, "Number of synonyms 1");
        AssertEqual(GetSynonymCount(synonyms, "z"), 0u, "Number of synonyms 0");
    }
}

void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "AreSynonyms a b");
        Assert(!AreSynonyms(empty, "b", "a"), "AreSynonyms b a");
    }

    {
        Synonyms synonyms = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "AreSynonyms a b");
        Assert(AreSynonyms(synonyms, "b", "a"), "AreSynonyms b a");
        Assert(AreSynonyms(synonyms, "a", "c"), "AreSynonyms a c");
        Assert(AreSynonyms(synonyms, "c", "a"), "AreSynonyms c a");
        Assert(AreSynonyms(synonyms, "b", "c"), "AreSynonyms b c");
        Assert(AreSynonyms(synonyms, "c", "b"), "AreSynonyms c b");        
    }
}

void TestAll(){
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(AreSynonyms, "AreSynonyms");
}
// comment