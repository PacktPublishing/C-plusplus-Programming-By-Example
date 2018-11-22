#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>
#include <string>

#pragma region Helper functions
template<typename Container, typename Iterator = typename Container::iterator>
void print_container(Container container)
{
	std::copy(container.begin(), container.end(),
		std::ostream_iterator<typename Container::value_type>(std::cout, " "));
	std::cout << std::endl;
}
template<typename T>
void print_vector(std::vector<T> data, std::string info_text = "", bool with_new_line = true)
{
	if (!info_text.empty()) std::cout << info_text.c_str();
	/* Print path vector to console */
	std::copy(data.begin(), data.end(), 
		std::ostream_iterator<int>(std::cout, " "));
	if (with_new_line) std::cout << std::endl;
}
#pragma endregion

using contact = std::tuple<std::string, std::string, std::string>;
using contacts = std::vector<contact>;

contacts demo_contacts = 
{
	{"Javon", "Bernard", "555-667-2345"},
	{"Kiana", "Lester", "234-745-4534"},
	{"Lia", "Baldwin", "546-234-7578"},
	{"Ryleigh", "Liu", "094-242-7745"},
	{"Shea", "Gibbs", "251-647-8941"},
	{"Sabrina", "Galvan", "345-798-3168"},
	{"Glenn", "Henry", "654-984-8664"},
	{"Lucia", "Wright", "134-798-6464"},
	{"Annika", "Carr", "461-641-7497"},
	{"Bruno", "Frank", "465-065-4610"}
};

inline std::ostream& operator<<(std::ostream& output, const contact &person)
{
	output << std::get<1>(person) << ", " << std::get<0>(person) 
		<< ": " << std::get<2>(person);
	return output;
}

bool compare_by_first_name(const contact& first, const contact &second)
{
	return std::get<0>(first) < std::get<0>(second);
}

bool compare_by_last_name(const contact& first, const contact& second)
{
	return std::get<1>(first) < std::get<1>(second);
}

bool compare_by_phone_number(const contact& first, const contact& second)
{
	return std::get<2>(first) < std::get<2>(second);
}

void print_contacts(const contacts& list)
{
	std::for_each(list.begin(), list.end(),
		[](const contact& contact)
	{
		std::cout << contact << std::endl;
	});
}

int main(int argc, char* argv[])
{
	std::cout << "Sort by first name..." << std::endl;
	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_by_first_name);
	print_contacts(demo_contacts);
	std::cout << std::endl;
	
	std::cout << "Sort by last name..." << std::endl;
	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_by_last_name);
	print_contacts(demo_contacts);
	std::cout << std::endl;

	std::cout << "Sort by phone number..." << std::endl;
	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_by_phone_number);
	print_contacts(demo_contacts);
	std::cout << std::endl;

	std::cout << "Searching for people..." << std::endl;
	std::vector<contact> people_with_b;
	std::copy_if(demo_contacts.begin(), demo_contacts.end(), 
		std::back_inserter(people_with_b), [](const contact& person)
	{
		auto first_name = std::get<0>(person);
		return first_name.find('L') != std::string::npos;
	});

	print_contacts(people_with_b);

	return 0;
}
