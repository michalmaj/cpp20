#include <iostream>
#include <string_view>
#include <map>

enum class Month
{
	Jan, Feb, Mar,
	Apr, May, Jun,
	Jul, Aug, Sep, September = Sep,
	Oct = 20, Nov, Dec
};

std::string_view month_to_string(Month month)
{
	switch (month)
	{
        /*
        case Month::Jan : return "January";
        case Month::Feb : return "February";
        case Month::Mar : return "March";
        case Month::Apr : return "April";
        case Month::May : return "May";
        case Month::Jun : return "June";
        case Month::Jul : return "July";
        case Month::Aug : return "August";
        case Month::Sep : return "September";
        case Month::Oct : return "October";
        case Month::Nov : return "November";
        case Month::Dec : return "December";
        default : return "None";
        */
		using enum Month; // since C++20
	    case Jan: return "January";
	    case Feb: return "February";
	    case Mar: return "March";
	    case Apr: return "April";
	    case May: return "May";
	    case Jun: return "June";
	    case Jul: return "July";
	    case Aug: return "August";
	    case Sep: return "September";
	    case Oct: return "October";
	    case Nov: return "November";
	    case Dec: return "December";
	    default: return "None";
	}
}

std::string_view month_to_string_map(Month month)
{
	using enum Month; // Since C++
	std::map<Month, std::string_view> m
	{
		{Jan, "January"}, {Feb, "February"}, {Mar, "March"}, {Apr, "April"},
		{May, "May"}, {Jun, "June"}, {Jul, "July"}, {Aug, "August"},
		{Sep, "September"}, {Oct, "October"}, {Nov, "November"}, {Dec, "December"}
	};
	if (!m.contains(month))
		return "None";
	return m.at(month);
}

int main()
{
	Month month{ Month::Jul };

	std::cout << "month: " << month_to_string(month) << std::endl;

	std::cout << "month: " << month_to_string_map(month) << std::endl;

	return 0;
}