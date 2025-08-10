# 🏋️ Fitness Tracking System

A C++ program that helps users track their fitness metrics, food intake, exercise routines, and provides personalized recommendations.

## 🌟 Features
- **User Profile Management**: Store name, age, weight, and height
- **Food Database**: Track calorie intake with 19 default food items
- **Exercise Database**: Monitor calories burned with 4 default exercises
- **BMI Calculator**: Calculate and categorize Body Mass Index
- **Smart Recommendations**: Get exercise suggestions based on calorie surplus
- **Daily Food Logging**: Record consumed foods throughout the day

## 🛠️ Technical Implementation
- **Object-Oriented Programming**: Clean class structure with proper encapsulation
- **STL Containers**: Uses `vector` for efficient data storage
- **Modular Design**: Separated concerns into logical classes
- **Interactive Menu**: User-friendly console interface

## 📋 Class Structure
| Class | Purpose |
|-------|---------|
| `Food` | Stores food/exercise names and calorie values |
| `FoodList` | Manages collection of food items |
| `ExerciseList` | Manages collection of exercises |
| `User` | Handles user profile information |
| `FitnessTracker` | Core system with tracking and recommendation logic |

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Standard Library support

### Compilation & Execution
```bash
g++ FitnessTracker.cpp -o FitnessTracker
./FitnessTracker
```

## 🖥️ Usage Example
1. Create your profile (Option 1)
2. Add consumed foods (Option 7)
3. Get exercise recommendations (Option 8)
4. Check your BMI (Option 9)

## 📊 Sample Output
```
Your Total Consumed Calorie is: 2850
Your Consumed Extra 600 Calorie

You can do any Exercise of the Following:
Do Walking for 90 min
Do Running for 40 min
Do Cycling for 60 min
Do Play Football for 45 min
```

## 📝 Default Data
**Foods Included:**
- Rice (500 cal)
- Meat (450 cal)
- Egg (80 cal)
- 16 other common foods

**Exercises Included:**
- Walking (400 cal/hr)
- Running (900 cal/hr)
- Cycling (600 cal/hr)
- Football (800 cal/hr)

## 📜 License
This project is open source under the MIT License.
