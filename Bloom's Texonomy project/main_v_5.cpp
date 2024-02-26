#include <iostream>
#include <set>
#include <string>
#include <cctype>

using namespace std;

class BloomsTexonomy {
private:
    set<string> Remembering;
    set<string> Understanding;
    set<string> Applying;
    set<string> Analyzing;
    set<string> Evaluating;

public:

// Using constructor to initialize the action word to specific Level.
    BloomsTexonomy() {
        Remembering = {
            "extract", "recall", "reproduce", "cite", "locate",
            "tabulate", "list", "memorize", "remember", "recollect", "recall", "reactivate",
            "cite", "recount", "memorize", "reproduce", "List", "enumerate", "itemize", "catalog",
            "tabulate", "name", "count", "characterize", "describe", "specify", "title", "designate",
            "classify", "detect", "spot", "pinpoint", "locate", "classify", "Define", "characterize",
            "recount", "pair", "Recite", "retell", "rehearse", "echo", "reproduce", "imitate", "Express",
            "articulate", "formulate", "announce", "proclaim", "present", "declare"
        };

        Understanding = {
            "translate", "paraphrase", "simplify", "decode", "infer", "construe",
            "condense", "abridge", "encapsulate", "highlight", "reinterpret",
            "rephrase", "restate", "express", "differently", "discriminate"
        };

        Applying = {
            "exhibit", "enact", "show", "showcase", "display", "perform", "act out",
            "calculate", "figure out", "resolve", "crack", "overcome", "troubleshoot",
            "compute", "estimate", "quantify", "assess", "determine", "prioritize", "elect",
            "implement", "employ", "utilize", "leverage", "operate", "manipulate",
            "modify", "alter", "adapt", "transform", "revise", "adjust", "convert",
            "find out", "uncover", "reveal", "unearth", "learn", "option for", "pick",
            "test", "trial", "research", "exemplify", "change", "amend"
        };

        Analyzing = {
            "deduce", "conclude", "reason", "interpret", "extrapolate", "predict",
            "clarify", "elucidate", "justify", "break down", "dissect", "study", "match",
            "isolate", "relate", "link", "combine", "Chart", "map", "sketch"
        };

        Evaluating = {
            "appraise", "critique", "weigh", "examine", "detect", "uncover", "advocate for", "promote",
            "appraise", "critique", "rate", "judge", "Rank", "order", "sequence", "schedule", "organize",
            "support", "argue for", "Propose", "suggest", "advise", "offer", "prescribe"
        };
    }
// Methode for Inserting in a specific level.
    void InsertWord() {
        int level;
        string word;

        cout << "1. Remembering." << endl;
        cout << "2. Understanding." << endl;
        cout << "3. Applying." << endl;
        cout << "4. Analyzing." << endl;
        cout << "5. Evaluating." << endl;

        cout << "Enter in which level you want to insert: ";
        cin >> level;

        cout << "Enter the word you want to insert: ";
        cin >> word;

        switch (level) {
            case 1:
                Remembering.insert(word);
                break;
            case 2:
                Understanding.insert(word);
                break;
            case 3:
                Applying.insert(word);
                break;
            case 4:
                Analyzing.insert(word);
                break;
            case 5:
                Evaluating.insert(word);
                break;
            default:
                cout << "Invalid level." << endl;
                break;
        }
    }
// Method that combine all the set into one and a nested loop check in which Level the given question is!

    void SearchWordInSets(const string& sentence) {
        set<string> sets[5] = {Remembering, Understanding, Applying, Analyzing, Evaluating};
        bool found = false;
        for (const auto& set : sets) {
            for (const auto& word : set) {
                if (sentence.find(word) != string::npos) {
                    cout << "The word \"" << word << "\" is present in the ";
                    if (set == Remembering) {
                        cout << "Remembering Level";
                    } else if (set == Understanding) {
                        cout << "Understanding Level";
                    } else if (set == Applying) {
                        cout << "Applying Level";
                    } else if (set == Analyzing) {
                        cout << "Analyzing Level";
                    } else if (set == Evaluating) {
                        cout << "Evaluating Level";
                    }
                    cout << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "No word from the sets is present in the sentence." << endl;
        }
    }
};


int main() {
    int n;
    BloomsTexonomy taxonomy;
    //Goto statement!
    First_choice:
    string sentence;

    cout << endl;
    cout << "1. Insert."<<endl;
    cout << "2. Search."<<endl;
    cout << "3. Exit."<<endl;
    
    cout << "Enter your choice : ";
    cin >> n;
    do {
        if ( n == 1)
        {
            taxonomy.InsertWord();
            goto First_choice;
            
        }
        else if (n == 2){
            cout << "Enter a sentence: ";
            cin.ignore();
            getline(cin, sentence);
            taxonomy.SearchWordInSets(sentence);
           
        }
        else if (n == 3)
        {
            cout << endl<< " Thank You";
            break;
        }
       goto First_choice;  
    }while(n != 3);
     

    

    return 0;
}