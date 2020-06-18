// Yunus Kara 1306180061 17.06.2020
// Shopping List Planner
// Compiled with Microsoft Visual Studio 2019

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Tum productlari kapsayan bir class tanimladim. Liste turu farketmeksizin tum urunler id'ye gore ayrýlýyor.
class Products {
public:
    string id="";
    vector<string> title;
    vector<int> amount;
    
};

int main()
{
    // Gerekli tanýmlamalar yapýldý.
    int amount;
    string title;
    int intInput;
    int intInput1;
    int intInput2;
    string stringInput;
    vector<string> listname;
    int listCount = 0;
    // Vektör içinde class.. Aslýnda burada verktörün her bir elemeaný bir liste olarak ayarlandý. O listeler'de kendi içinde productlara sahip.
    vector<Products> shoppingList;
    // Maksimum liste sayýsý
    shoppingList.resize(999);
    // UI kýsýmlarýnýn inþaasý..
    cout << "\nWelcome the Shopping List App!\n***************************************" << endl;
    do {
        cout << "Main Menu:\n1. Create new List\n2. Show and Set your Shopping Lists\n3. Exit from Shopping List App!" << endl;
        cout << "***************************************" << endl;
        cout << "Please select the action you want to take.(1,2 or 3)\n";
        cout << "The action you want to take: ";
        cin >> intInput;
        // Girilen sayinin int olup olmadigi kontrolu
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "***\tPlease enter only number!!!\t***"<<endl;
        }
        else {
            if (intInput == 1) {
                cout << "Please define a name for your list: ";
                cin.ignore();
                getline(cin, stringInput);
                shoppingList[listCount].id = stringInput;
                listCount++;
            }
            else if (intInput == 2) {
                do {
                    cout << "The shopping lists you have: " << endl;
                    for (int i = 0; i < listCount; i++) {
                        cout << i + 1 << "." << shoppingList[i].id << endl;
                    }
                    cout << "Press 0 Go back to Main menu!\nWhich list do you want to see or change?(Like 0,1,2,3..)" << endl;
                    cout << "The action you want to take: ";
                    cin.ignore();
                    cin >> intInput1;
                    // Girilen sayinin int olup olmadigi kontrolu
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "***\tPlease enter only numbers!!!\t***" << endl;
                    }
                    else {
                        // intInput1 aslýnda bizim liste id'miz, 2 girildiðinde (index 0 dan baþladðý için) 1.tanýmlanan listeye ulaþabiliyoruz.
                        if (intInput1 != 0 && intInput1 <= listCount) {
                            do {
                                // Yapýlabilecekler gösterilip her bir case için ayrý ayrý durumlar oluþturuldu..
                                cout << "What do you want to see or change in the " << shoppingList[intInput1 - 1].id << "\n1. Add Item\n2. Edit Item\n"
                                    "3. Delete Item\n4. Mark as Done\n5. Go back to Lists menu!" << endl;
                                cout << "The action you want to take: ";
                                cin.ignore();
                                cin >> intInput2;
                                // Girilen sayinin int olup olmadigi kontrolu
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore();
                                    cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                }
                                else {
                                    // Add ITEM
                                    if (intInput2 == 1) {
                                        cout << "Enter the name and quantity of the product you want to add;" << endl;
                                        cout << "Name of the product: ";
                                        cin.ignore();
                                        getline(cin, title);
                                        cout << "amount of the product: ";
                                        cin >> amount;
                                        // Girilen sayinin int olup olmadigi kontrolu
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore();
                                            cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                        }
                                        else {
                                            shoppingList[intInput1 - 1].title.push_back(title);
                                            shoppingList[intInput1 - 1].amount.push_back(amount);
                                            string mark = " (Bought!!)  ";
                                            cout << "Your " << shoppingList[intInput1 - 1].id << " has these:" << endl;
                                            for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                                cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                            }
                                        }
                                    }
                                    //EDIT ITEM
                                    else if (intInput2 == 2) {
                                        int index2;
                                        string mark = " (Bought!!)  ";
                                        cout << "Your " << shoppingList[intInput1 - 1].id << " has these:" << endl;
                                        for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                            cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                        }
                                        cout << "Which product's information do you want to edit?(like 1,2,3..): ";
                                        cin.ignore();
                                        cin >> index2;
                                        // Girilen sayinin int olup olmadigi kontrolu
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore();
                                            cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                        }
                                        else {
                                            if (index2 > 0 && index2 <= shoppingList[intInput1 - 1].title.size()) {
                                                string title1; int amount1;
                                                cout << "Enter the name and quantity of the product you want to add; " << endl;
                                                cout << "Name of the product: ";
                                                cin.ignore();
                                                getline(cin, title1);
                                                cout << "amount of the product: ";
                                                cin >> amount1;
                                                // Girilen sayinin int olup olmadigi kontrolu
                                                if (cin.fail()) {
                                                    cin.clear();
                                                    cin.ignore();
                                                    cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                                }
                                                else {
                                                    shoppingList[intInput1 - 1].title[index2 - 1] = title1;
                                                    shoppingList[intInput1 - 1].amount[index2 - 1] = amount1;
                                                    cout << "Your product has been successfully edited." << endl;
                                                    for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                                        cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                                    }
                                                }
                                            }
                                            else {
                                                cout << "***\tProduct not found!! Please write the correct number of your product.\t***" << endl;
                                            }
                                        }
                                    }
                                    // DELETE ITEM
                                    else if (intInput2 == 3) {
                                        int index1;
                                        string mark = " (Bought!!)  ";
                                        cout << "Your " << shoppingList[intInput1 - 1].id << " has these:" << endl;
                                        for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                            cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                        }
                                        cout << "Enter the number of products you want to delete(Like 1,2,3..): ";
                                        cin.ignore();
                                        cin >> index1;
                                        // Girilen sayinin int olup olmadigi kontrolu
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore();
                                            cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                        }
                                        else {
                                            if (index1 > 0 && index1 <= shoppingList[intInput1 - 1].title.size()) {
                                                shoppingList[intInput1 - 1].title.erase(shoppingList[intInput1 - 1].title.begin() + index1 - 1);
                                                shoppingList[intInput1 - 1].amount.erase(shoppingList[intInput1 - 1].amount.begin() + index1 - 1);
                                                cout << "Your product has been successfully deleted." << endl;
                                                for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                                    cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                                }
                                            }
                                            else {
                                                cout << "***\tProduct not found!! Please write the correct number of your product.\t***" << endl;
                                            }
                                        }
                                        
                                    }
                                    // MARK ITEM
                                    else if (intInput2 == 4) {
                                        int index3;
                                        string mark = " (Bought!!)  ";
                                        cout << "Your " << shoppingList[intInput1 - 1].id << " has these:" << endl;
                                        for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                            cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                        }
                                        cout << "Which product do you want to mark?(Like 1,2,3..): ";
                                        cin.ignore();
                                        cin >> index3;
                                        // Girilen sayinin int olup olmadigi kontrolu
                                        if (cin.fail()) {
                                            cin.clear();
                                            cin.ignore();
                                            cout << "***\tPlease enter only numbers!!!\t***" << endl;
                                        }
                                        else {
                                            if (index3 > 0 && index3 <= shoppingList[intInput1 - 1].title.size()) {
                                                shoppingList[intInput1 - 1].title[index3 - 1] = mark + shoppingList[intInput1 - 1].title[index3 - 1];
                                                cout << "Your product's mark has been successfully edited." << endl;
                                                for (int i = 0; i < shoppingList[intInput1 - 1].title.size(); i++) {
                                                    cout << i + 1 << "." << shoppingList[intInput1 - 1].title[i] << " " << shoppingList[intInput1 - 1].amount[i] << endl;
                                                }
                                            }
                                            else {
                                                cout << "***\tProduct not found!! Please write the correct number of your product.\t***" << endl;
                                            }
                                        }
                                       
                                    }
                                    else if (intInput2 == 5) {

                                    }
                                    else {
                                        cout << "\n***\tPlease enter a number between 1 and 5.\t***\n" << endl;
                                    }
                                }
                                
                            } while (intInput2 != 5);
                        }
                        else if (intInput1 > listCount) {
                            cout << "\n***\tPlease enter a number between 0 and the number of lists you add!!!\t***\n" << endl;
                        }
                    }

                } while (intInput1 != 0);
            }
            else if (intInput == 3) {
                cout << "\n*****\tSee you soon...\t*****\n" << endl;
            }
            else {
                cout << "\n***\tPlease make sure to choose 1,2 or 3 numbers!!!\t***\n" << endl;
            }
        }
        
    } while (intInput != 3);
    
    return 0;
}