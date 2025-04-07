#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<iomanip>
using namespace std;

// Recipe Class
class Recipe {                          //done
private:                      //private member
    string recipe_id;
    string recipe_name;
    string Chef_name;
    string weight;
    string price;
    string no_quantity;

public:                //public member
    //All Getter function
    string getRecipeId()
    {
        return recipe_id;
    }
    string getRecipeName()
    {
        return recipe_name;
    }
    string getRecipeChefName()
    {
        return Chef_name;
    }
    string getWeight()
    {
        return weight;
    }
    string getPrice()
    {
        return price;
    }
    string getQuantity()
    {
        return no_quantity;
    }


   //All Setter function
    void setRecipeId(string recipe_id)
    {
        this->recipe_id = recipe_id;
    }
    void setRecipeName(string recipe_name)
    {
        this->recipe_name = recipe_name;
    }
    void setRecipeChefName(string Chef_name)
    {
        this->Chef_name = Chef_name;
    }
    void setWeight(string weight)
    {
        this->weight = weight;
    }
    void setPrice(string price)
    {
        this->price = price;
    }
    void setQuantity(string no_quantity)
    {
        this->no_quantity = no_quantity;
    }

	void control_panel();
};
void Recipe::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL"<<endl;
	cout << "\n\n1. ADD RECIPE"<<endl;
	cout << "\n2. DISPLAY ALL RECIPE INFORMATION"<<endl;
	cout << "\n3. SEARCH PARTICULAR RECIPE"<<endl;
	cout << "\n4. UPDATE RECIPE"<<endl;
	cout << "\n5. DELETE RECIPE"<<endl;
	cout << "\n6. ORDER RECIPE"<<endl;
	cout << "\n7. EXIT"<<endl;
}
class AddRecipe : public Recipe{         //done

private:
    string str_input;
public :
    void add_recipe()
    {
        system("cls");
        fstream file;
        cout << "\n\n\t\t\t\tADD RECIPES";
        cout << "\n\nRecipe ID : ";
        cin >> str_input;
        setRecipeId(str_input);
        cout << "\nRecipe Name : ";
        cin >> str_input;
        setRecipeName(str_input);
        cout << "\nChef Name : ";
        cin >> str_input;
        setRecipeChefName(str_input);

        cout << "\nWeight : ";
        cin >> str_input;
        setWeight(str_input);
        cout << "\nPrice : ";
        cin >> str_input;
        setPrice(str_input);


        cout << "\nQuantity of Recipes : ";
        cin >> str_input;
        setQuantity(str_input);
        file.open("E:// recipe.txt",ios::out | ios::app);
        file << " " << getRecipeId()
             << " " << getRecipeName()
             << " " << getRecipeChefName()
             << " " << getWeight()
             << " " << getPrice()
             << " " << getQuantity()
             << "\n";
        file.close();
    }
};

class DeleteRecipe : public AddRecipe{
private:
    string delete_ID;
    string str_input;
public:
    void del_recipe()
    {
        system("cls");
        fstream file, file1;
        int count = 0;
        cout << "\n\n\t\t\t\tDelete a Recipe";
        file1.open("E:// recipe1.txt",ios::app | ios::out);
        file.open("E:// recipe.txt",ios::in);

        if (!file)
            cout << "\n\nFile Opening Error...";
        else {
            cout << "\n\nRecipe ID : ";
            cin >> delete_ID;
            file >> str_input;
            setRecipeId(str_input);
            file>> str_input;
            setRecipeName(str_input);
            file>> str_input;
            setRecipeChefName(str_input);

            file>> str_input;
            setWeight(str_input);
            file>> str_input;
            setPrice(str_input);

            file>> str_input;
            setQuantity(str_input);
            while (!file.eof()) {

                if (delete_ID == getRecipeId()) {

                    system("cls");
                    cout << "\n\n\t\t\t\t"
                        << "Delete a Recipe";
                    cout << "\n\nRecipe is Deleted Successfully...\n\n";
                    count++;
                }
                else
                    file1 << " " << getRecipeId()
                          << " " << getRecipeName()
                          << " " << getRecipeChefName()
                          << " " << getWeight()
                          << " " << getPrice()
                          << " " << getQuantity()
                          << "\n\n";
                file >> str_input;
                setRecipeId(str_input);
                file>> str_input;
                setRecipeName(str_input);
                file>> str_input;
                setRecipeChefName(str_input);

                file>> str_input;
                setWeight(str_input);
                file>> str_input;
                setPrice(str_input);

                file>> str_input;
                setQuantity(str_input);
            }
            if (count == 0)
                cout << "\n\nRecipe ID Not Found...";
        }
        system("pause");

        // Close the file
        file.close();
        file1.close();
        remove("E:// recipe.txt");
        rename("E:// recipe1.txt","E:// recipe.txt");
    }

};

class ShowRecipe : public DeleteRecipe{     //Show class
private:
    string str_input;
public:
   void show_recipe()
   {
        system("cls");
        fstream file;
        cout << "\n\n\t\t\t\t\tAll RECIPES";
        file.open("E:// recipe.txt", ios::in);
        if (!file)
            cout << "\n\nFile Opening Error!";
        else{
            cout << "\n\n\n"<< setw(15)<<left<<"Recipe ID"<< setw(15)
                 <<left<<"Recipe"<< setw(15)<<left<<"Chef"<<setw(15)
                 <<left<<"Weight"<<setw(15)<<left<<"Price"<<"Quantity\n\n";
            file >> str_input;
            setRecipeId(str_input);
            file>> str_input;
            setRecipeName(str_input);
            file>> str_input;
            setRecipeChefName(str_input);

            file>> str_input;
            setWeight(str_input);
            file>> str_input;
            setPrice(str_input);

            file>> str_input;
            setQuantity(str_input);

            // Till end of file is reached
            while (!file.eof()) {

                cout << setw(15)<<left<<getRecipeId()<< setw(15)<<left<< getRecipeName()
                     << setw(15)<<left<<getRecipeChefName()<< setw(15)<<left<<getWeight()
                     << setw(15)<<left<<getPrice()<< getQuantity()<< "\n\n";
                file >> str_input;
                setRecipeId(str_input);
                file>> str_input;
                setRecipeName(str_input);
                file>> str_input;
                setRecipeChefName(str_input);

                file>> str_input;
                setWeight(str_input);
                file>> str_input;
                setPrice(str_input);

                file>> str_input;
                setQuantity(str_input);
            }

            system("pause");

            // Close the file
            file.close();
        }
    }
};

class SearchRecipe:public Recipe{            //done
private:
    string search_ID;
    string str_input;
public:
    void search_recipe(){
        system("cls");
        fstream file;
        int count = 0;
        cout << "\n\n\t\t\t\tSearch Particular Recipe";
        // Open the file in input mode
        file.open("E:// recipe.txt", ios::in);
        if (!file)
            cout << "\n\nFile Opening Error!";
        else {

            cout << "\n\nRecipe ID : ";
            cin >> search_ID;
            file >> str_input;
            setRecipeId(str_input);
            file>> str_input;
            setRecipeName(str_input);
            file>> str_input;
            setRecipeChefName(str_input);

            file>> str_input;
            setWeight(str_input);
            file>> str_input;
            setPrice(str_input);

            file>> str_input;
            setQuantity(str_input);
            while (!file.eof()) {
                if (search_ID == getRecipeId()) {
                    system("cls");
                    cout << "\n\n\t\t\t\t"<< "Particular Recipe";
                    cout << "\n\nRecipe ID : "<< getRecipeId()<<endl;
                    cout << "\nName : "<< getRecipeName()<<endl;
                    cout << "\nChef : "<< getRecipeChefName()<<endl;
                    cout << "\nWeight : "<< getWeight()<<endl;
                    cout << "\nPrice : "<< getPrice()<<endl;
                    cout << "\nQuantity: "<< getQuantity()<<endl;
                    cout << endl<<endl;
                    count++;
                    break;
                }
                file >> str_input;
                setRecipeId(str_input);
                file>> str_input;
                setRecipeName(str_input);
                file>> str_input;
                setRecipeChefName(str_input);

                file>> str_input;
                setWeight(str_input);
                file>> str_input;
                setPrice(str_input);

                file>> str_input;
                setQuantity(str_input);
            }
            system("pause");
            file.close();
            if (count == 0)
                cout << "\n\nRecipe ID Not Found...";
        }
    }
};


class UpdateRecipe: public SearchRecipe{
private:
    string str_input;
    string update_ID;
public:
    void update_recipe()
    {
        system("cls");
        fstream file, file1;
        int count = 0;
        cout << "\n\n\t\t\t\tUpdate Recipe Record";
        file1.open("E:// recipe1.txt",ios::app | ios::out);
        file.open("E:// recipe.txt", ios::in);

        if (!file)
            cout << "\n\nFile Opening Error!";
        else {

            cout << "\n\nRecipe ID : ";
            cin >> update_ID;
            file >> str_input;
            setRecipeId(str_input);
            file>> str_input;
            setRecipeName(str_input);
            file>> str_input;
            setRecipeChefName(str_input);

            file>> str_input;
            setWeight(str_input);
            file>> str_input;
            setPrice(str_input);

            file>> str_input;
            setQuantity(str_input);

            while (!file.eof()) {
                if (update_ID == getRecipeId()) {
                    system("cls");
                    cout << "\t\t\t\t"<<"Update Recipe Record";
                    cout << "\n\nNew Recipe Name : ";
                    cin >> str_input;
                    setRecipeName(str_input);
                    cout << "\nChef Name : ";
                    cin >> str_input;
                    setRecipeChefName(str_input);


                    cout << "\nWeight : ";
                    cin >> str_input;
                    setWeight(str_input);
                    cout << "\nPrice : ";
                    cin >> str_input;
                    setPrice(str_input);

                    cout << "\nQuantity : ";
                    cin >> str_input;
                    setQuantity(str_input);
                    file1 << " " << getRecipeId()
                          << " " << getRecipeName()
                          << " " << getRecipeChefName()
                          << " " << getWeight()
                          << " " << getPrice()
                          << " " << getQuantity()
                          << "\n\n";
                    count++;
                }
                else
                    file1 << " " << getRecipeId()
                          << " " << getRecipeName()
                          << " " << getRecipeChefName()
                          << " " << getWeight()
                          << " " << getPrice()
                          << " " << getQuantity()
                          << "\n\n";
                file >> str_input;
                setRecipeId(str_input);
                file>> str_input;
                setRecipeName(str_input);
                file>> str_input;
                setRecipeChefName(str_input);

                file>> str_input;
                setWeight(str_input);
                file>> str_input;
                setPrice(str_input);

                file>> str_input;
                setQuantity(str_input);
            }
            if (count == 0)
                cout << "\n\nRecipe ID Not Found...";
        }
        cout << endl;
        system("pause");

        // Close the files
        file.close();
        file1.close();
        remove("E:// recipe.txt");      //remove first recipe file
        rename("E:// recipe1.txt","E:// recipe.txt");//rename second recipe file recipe1.text to recipe.text
    }

};

class ReciveRecipeOrder: public Recipe{
private:
    string str_input;
    string order_recipe_ID;
    string order_quantity;
public:
    void recive_order()
    {
        system("cls");
        fstream file, file1;
        int count = 0;
        cout << "\n\n\t\t\t\tRecive Recipe Order";
        file1.open("E:// recipe1.txt",ios::app | ios::out);
        file.open("E:// recipe.txt", ios::in);

        if (!file)
            cout << "\n\nFile Opening Error!";
        else {

            cout << "\n\nRecipe ID : ";
            cin >> order_recipe_ID;
            file >> str_input;
            setRecipeId(str_input);
            file>> str_input;
            setRecipeName(str_input);
            file>> str_input;
            setRecipeChefName(str_input);

            file>> str_input;
            setWeight(str_input);
            file>> str_input;
            setPrice(str_input);

            file>> str_input;
            setQuantity(str_input);
            while (!file.eof()) {
                if (order_recipe_ID == getRecipeId()) {
                    system("cls");
                    cout << "\t\t\t\t"<< "Recive Recipe Order";
                    cout << "\n\nEnter Quantity(How many oder you) : ";
                    cin >> order_quantity;
                    int id1, id2;
                    id1 = stoi(getQuantity());    //available quantity
                    id2 = stoi(order_quantity);        //how many order
                    if(id1<id2)
                    {
                        cout<<"Not enough stock.";
                        count++;
                        file1 << " " << getRecipeId()
                              << " " << getRecipeName()
                              << " " << getRecipeChefName()
                              << " " << getWeight()
                              << " " << getPrice()
                              << " " << getQuantity()
                              << "\n\n";
                    }
                    else{
                        setQuantity(to_string(id1-id2));   //convert int to string
                        file1 << " " << getRecipeId()
                              << " " << getRecipeName()
                              << " " << getRecipeChefName()
                              << " " << getWeight()
                              << " " << getPrice()
                              << " " << getQuantity()
                              << "\n\n";
                        count++;
                        cout<<"YOUR ORDER SUCCESSFULLY SAVED"<<endl;
                    }
                }
                else
                    file1 << " " << getRecipeId()
                          << " " << getRecipeName()
                          << " " << getRecipeChefName()
                          << " " << getWeight()
                          << " " << getPrice()
                          << " " << getQuantity()
                          << "\n\n";

                file >> str_input;
                setRecipeId(str_input);
                file>> str_input;
                setRecipeName(str_input);
                file>> str_input;
                setRecipeChefName(str_input);

                file>> str_input;
                setWeight(str_input);
                file>> str_input;
                setPrice(str_input);

                file>> str_input;
                setQuantity(str_input);
            }
            if (count == 0)
                cout << "\n\nRecipe ID Not Found...";
        }
        cout << endl;
        system("pause");

        // Close the files
        file.close();
        file1.close();
        remove("E:// recipe.txt");
        rename("E:// recipe1.txt","E:// recipe.txt");
    }

};

// Function for Recipe management record
void RecipeRecord()           //done
{
	string choice;
	char x;
	Recipe R;
	AddRecipe A;
	ShowRecipe SW;
	SearchRecipe S;
	UpdateRecipe U;
	DeleteRecipe D;
	ReciveRecipeOrder O;
	while(1){
        R.control_panel();
        t:
		cout << "\n\nEnter your choice (number) : ";
		cin >> choice;
		if(choice == "1"){
			do {
				A.add_recipe();
				cout << "\n\nWant to add another recipe? (y/n) : ";
				cin >> x;
			} while (x == 'y');

		}
		else if(choice=="2"){
			SW.show_recipe();
		}

		else if(choice=="3"){
			S.search_recipe();
		}
		else if(choice=="4"){
			U.update_recipe();
		}
		else if(choice=="5"){
			D.del_recipe();
		}
        else if(choice=="6"){
            O.recive_order();
        }
		else if(choice=="7"){
			exit(0);
			break;
		}

		else{
			cout << "\n\nINVALID CHOICE\n";
			goto t;

		}
	}
}
int main()                    //done
{
    string u_name, password;
    cout<<endl<<endl;                                   ///create login page class
    cout<<"\t\tWELLCOME TO RECIPE MANAGEMENT SYSTEM"<<endl<<endl;
    repet:
    cout<<endl<<endl;
    cout<<"Please enter your user_name and password : "<<endl<<endl;
    cout<<"User Name : ";
    cin>>u_name;
    cout<<endl;
    cout<<"Password : ";
    cin>>password;
    if(u_name=="1"&&password=="1")
        RecipeRecord();// Function Call
    else
    {
        cout<<endl;
        cout<<"Invalid user_name or password.Please enter any key to try again.\n"<<endl;
        getchar();
        goto repet;
    }
	return 0;
}
