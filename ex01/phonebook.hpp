# ifndef PHONEBOOK
#  define PHONEBOOK

# include <iostream>
# include <cctype>
# include <string>
# include <sstream>
# include <iomanip>

class contact {
	private:
		int			_id;
		std::string	_FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string	_Number;
		std::string _Secret;
	public:
		void SetFirstName(const std::string name) {
			_FirstName = name;
		};
		void SetLastName(const std::string name) {
			_LastName = name;
		};
		void SetNickName(const std::string name) {
			_Nickname = name;
		};
		void SetNumber(const std::string number) {
			_Number = number;
		};
		void SetSecret(const std::string secret) {
			_Secret = secret;
		};
		void SetIndex(int id) {
			_id = id;
		};
		std::string GetFirstName() const {
			return (_FirstName);
		};
		std::string GetLastName() const {
			return (_LastName);
		};
		std::string GetNickName() const {
			return (_Nickname);
		};
		std::string GetSecret() const {
			return (_Secret);
		};
		std::string GetNumber() const {
			return (_Number);
		};
		int GetIndex() const {
			return (_id);
		};
};

class phonebook {
	private:
		contact book[8];
	public:
		void Add(int i);
		void Search(int max);
		void Exit();
};

#endif