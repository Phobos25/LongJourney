#include "test_runner.h"

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

void TestAll(){
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
}