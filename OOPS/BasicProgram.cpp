#include <iostream>
#include <string>

/*
class date that  we can initiate to modify the date info
*/
class Date{
    private:

        int main_month,main_date,main_year;            //Private variables that are the main variables

        void print_date(){                                    //Print the date that we have set
            std::cout << "Date: " << main_date << std::endl << "Month: " << main_month << std::endl << "Year: " << main_year << std::endl;
        }

        bool is_leap_year(int year){                          //Check if the year is a leap year or not
            if(year % 4){                                     //return true if the year is a leap year
                return false;
            }
            return true;
        }

        bool check_validity_month(int month){            //function to check if the given month is valid or not
            if(month <13 && month >=1)                               //check if the month is less than 13. if more then the value is invalid
            {
                return true;
            }
            std::cout << "Month should be between 1 and 12" << std::endl;
            return false;
        }

        bool check_for_31_days(int date){                //check if date is valid for month that has 31 days
            if (date <32){
            return true;
            }
            std::cout << "This month only has 31 days" << std::endl;
            return false;
        }

        bool check_for_30_days(int date){                //check if date is valid for month that has 30 days
            if (date <31){
            return true;
            }
            std::cout << "This month only has 30 days" << std::endl;
            return false;
        }

        bool check_if_feb_date_isValid(int date, int year){          //check if date is valid for february
            if (is_leap_year(year)){
                if (date < 30){
                    return true;
                }
            std::cout << "It is a leap year and february has only 29 days" << std::endl;
            return false;
            }
            else{
                if (date < 29){
                    return true;
                }
            std::cout << "It is not a leap year and february has only 28 days" << std::endl;
            return false;
            }
        }

        bool check_if_date_is_valid(int date, int month, int year){         //check if input date is valid for each month
            if(date <= 0){
                std::cout << "Date starts from 1" << std::endl;
                return false;
            }
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)    //check for 31 days
                return check_for_31_days(date);
            else if (month == 4 || month == 6 || month == 9 || month == 11)    //check for 30 days
                return check_for_30_days(date);
            else
                return check_if_feb_date_isValid(date,year);                          //check for february
            return false;
        }

        bool check_date_validity(int month, int date, int year)  //Function that checks if the given data is actually valid or not
        {
            std::cout << "Checking validity of date" << std::endl;
            if(!(year > 1899 && year <= 2026)){               //check if the year is in between 1900 and 2026
                std::cout << "Year should be between 1900 and 2026" << std::endl;
                return false;
            }
            if(!(check_validity_month(month))){             //check if the given month is valid or not
                return false;
            }
            if(!(check_if_date_is_valid(date,month,year))){         //check if the date is valid or not
                return false;
            }
        return true;
        }

    public:
        void set_date(int month, int date, int year){       //Function that sets the date
            main_month=month;
            main_date=date;
            main_year=year;
            print_date();
        }
        Date(int month, int date, int year){
            if(check_date_validity(month, date, year)){           //When a class is initiated we check if the given input is valid or not, only then will we update the private variables
                set_date(month, date, year);
            }    
        };
};

int main(){
    std::cout << "First OOPS program with C++" << std::endl;
    Date(0,0,2026);
    return 0;
}