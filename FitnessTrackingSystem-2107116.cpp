#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Food{
    string name;
    float calorie;
  public:
     Food(string name,float calorie){
      this->name=name;
      this->calorie=calorie;
    }
    string getName(){
        return name;
    }
    float getCalorie(){
        return calorie;
    }
};

class FoodList{
   public:
    vector<Food>foodList;

    void addFood(Food food){
        foodList.push_back(food);
    }
    void showFoods(){
        cout<<"Food List:"<<endl;
        for(auto& food:foodList){
            cout<<food.getName()<<" - "<<food.getCalorie()<<" calories"<<endl;
        }
    }
};

class ExerciseList{
  public:
    vector<Food>exerciseList;

    void addExercise(Food exercise) {
        exerciseList.push_back(exercise);
    }
    void showExercises(){
        cout<<"Exercise List:"<<endl;
        for(auto& exercise:exerciseList) {
            cout<<exercise.getName()<<" - "<< exercise.getCalorie()<<" calories burned per hour"<<endl;
        }
    }
};

class User{
    string name;
    int age;
    float weight;
    float height;
  public:
    void getProfile(){
        cout<<"Enter your name: "<<endl;
        cin>>name;
        cout<<"Enter your age : "<<endl;
        cin>>age;
        cout<<"Enter your weight (kg): "<<endl;
        cin>>weight;
        cout<<"Enter your height (m): "<<endl;
        cin>>height;
    }
    float getWeight(){
        return weight;
    }
    float getHeight(){
        return height;
    }
    float getAge(){
        return age;
    }
    void friend ShowProfile(User&);
};

class FitnessTracker{
  public:
    vector<string>consumedFood;
    void addFood(FoodList& flist){
        string name;
        float calorie;
        cout<<"Enter food name: "<<endl;
        cin>>name;
        cout<<"Enter calories in the food: "<<endl;
        cin>>calorie;
        Food food(name,calorie);
        flist.addFood(food);
        cout<<"Food added successfully."<<endl;
    }
    void showFoodList(FoodList& flist){
        flist.showFoods();
    }
    void addExercise(ExerciseList& elist){
        string name;
        float caloriesBurned;
        cout<<"Enter exercise name: "<<endl;
        cin>>name;
        cout<<"Enter calories burned per hour for this exercise: "<<endl;
        cin>>caloriesBurned;
        Food exercise(name,caloriesBurned);
        elist.addExercise(exercise);
        cout<<"Exercise added successfully."<<endl;
    }
    void showExerciseList(ExerciseList& elist){
        elist.showExercises();
    }
    void getConsumedFood(){
        cout<<"Enter the foods you consumed in a full day(Type 'done' when finished):"<<endl;
        while(true){
        string food;
        cin>>food;
        if(food=="done")
            break;
        consumedFood.push_back(food);
        }
        cout<<"List of Consumed Food: "<<endl;
        for(auto cf:consumedFood)
          cout<<cf<<endl;
    }  
    
    void getRecommendation(ExerciseList& exlist,FoodList& f_list){
        float totalCalories=0;
        for(int i=0;i<consumedFood.size();i++)
          for(int j=0;j<f_list.foodList.size();j++)
            if(consumedFood[i]==f_list.foodList[j].getName())
                totalCalories+=f_list.foodList[j].getCalorie();
            else
               continue; 

    float avgCalorie = 2250.0;
    float netCalorie = totalCalories - avgCalorie;
    cout<<"Your Total Consumed Calorie is : "<<totalCalories<<endl;
    if(totalCalories<avgCalorie)
      cout<<"You Should Have Taken "<<avgCalorie-totalCalories<<" Calorie More Today"<<endl;
    else{
      cout<<"Your Consumed Extra "<<netCalorie<<" Calorie"<<endl<<endl;
      cout<<"You can do any Exercise of the Following :"<<endl;
      for(auto ex : exlist.exerciseList)
        cout<<"Do " <<ex.getName()<<" for "<<60*netCalorie/ex.getCalorie()<<" min"<<endl;
    }
    }
};

void showOptions(){
        cout<<"\n\n------------------------------"<<endl;
        cout<<" Options:"<<endl;
        cout<<" 1. Add Profile"<<endl;
        cout<<" 2. Show Profile"<<endl;
        cout<<" 3. Add Food"<<endl;
        cout<<" 4. Show Food List"<<endl;
        cout<<" 5. Add Exercise"<<endl;
        cout<<" 6. Show Exercise List"<<endl;
        cout<<" 7. Enter Consumed Food"<<endl;
        cout<<" 8. Get Exercise Recommendation"<<endl;
        cout<<" 9. Calculate BMI"<<endl;
        cout<<" 10. Exit"<<endl;
        cout<<"------------------------------\n"<<endl;
}

void ShowProfile(User& user){
        cout<<"Profile:"<<endl;
        cout<<"Name   : "<<user.name<<endl;
        cout<<"Age    : " <<user.age<<" years"<<endl;
        cout<<"Weight : " <<user.weight<<" kg"<<endl;
        cout<<"Height : " <<user.height<<" m"<<endl;
}

void BMI_Calculator(User& person){
    float height=(person.getHeight())*(person.getHeight());
    float bmi=person.getWeight()/height;
    cout<<"Your BMI is: "<<bmi<<endl;
    if(bmi<18.5)
        cout<<"You are Underweight"<<endl;
    else if(bmi>=18.5 && bmi<=24.9)
        cout << "Your Weight is Normal" << endl;
    else if (bmi >= 25 && bmi <= 29.9)
        cout<<"You are Overweight"<<endl;
    else if(bmi>=30 && bmi<=34.9)
        cout<<"You are Suffering from Obesity (Class 1)"<<endl;
    else if(bmi>=35 && bmi<=39.9)
        cout<<"You are Suffering from Obesity (Class 2)"<<endl;
    else
        cout<<"You are Suffering from Extreme Obesity (Class 3)"<<endl;
}

void setDefault(FoodList& foodlist,ExerciseList& exerciselist){
   foodlist.foodList.push_back(Food("Rice",500));
   foodlist.foodList.push_back(Food("Meat",450));
   foodlist.foodList.push_back(Food("Lentils",116));
   foodlist.foodList.push_back(Food("Egg",80));
   foodlist.foodList.push_back(Food("Fish",400));
   foodlist.foodList.push_back(Food("Ruti",100));
   foodlist.foodList.push_back(Food("Banana",110));
   foodlist.foodList.push_back(Food("Apple",95));
   foodlist.foodList.push_back(Food("Chicken",200));
   foodlist.foodList.push_back(Food("Vegetable",200));
   foodlist.foodList.push_back(Food("Pizza",900));
   foodlist.foodList.push_back(Food("Soup",76));
   foodlist.foodList.push_back(Food("Porota",250));
   foodlist.foodList.push_back(Food("Polao",500));
   foodlist.foodList.push_back(Food("Biriyani",800));
   foodlist.foodList.push_back(Food("Noodles",400));
   foodlist.foodList.push_back(Food("Milk",300));
   foodlist.foodList.push_back(Food("Burger",400));
   foodlist.foodList.push_back(Food("Ice_Cream",350));

   exerciselist.exerciseList.push_back(Food("Walking",400));
   exerciselist.exerciseList.push_back(Food("Running",900));
   exerciselist.exerciseList.push_back(Food("Cycling",600));
   exerciselist.exerciseList.push_back(Food("Play Football",800));
}

int callOptions(FitnessTracker& tracker,FoodList& defaultFood,ExerciseList& defaultExercises,User& user){
    do{ 
        showOptions();
        int choice;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
              user.getProfile();
              break;
            case 2:
              ShowProfile(user);
              break;
            case 3:
              tracker.addFood(defaultFood);
              break;
            case 4:
              tracker.showFoodList(defaultFood);
              break;
            case 5:
              tracker.addExercise(defaultExercises);
              break;
            case 6:
              tracker.showExerciseList(defaultExercises);
              break;
            case 7:
              tracker.getConsumedFood();
              break;
            case 8:
              tracker.getRecommendation(defaultExercises,defaultFood);
              break;
            case 9:
              BMI_Calculator(user);  
              break; 
            case 10:
              cout<<"Exiting the program."<<endl;
              return 0;
            default:
                cout << "Invalid Choice."<<endl;
                break;
        }
    }while(true);
}

int main(){

    cout<<"\n--------------------------------"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"  | FITNESS TRACKING SYSTEM |"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"--------------------------------\n"<<endl;

    FoodList defaultFood;
    ExerciseList defaultExercises;
    setDefault(defaultFood,defaultExercises);
    
    User user;
    FitnessTracker tracker;

    callOptions(tracker,defaultFood,defaultExercises,user);
    
    return 0;
}
