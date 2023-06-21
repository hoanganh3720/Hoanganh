
class Student {
private:
	string name;
	char gender;
public:
	Student() {
		name = "Unknown";
		gender = 'u';
	}

	Student(string name) {
		this->name = name;
		this->gender = 'u';
	}

	Student(char gender) {
		this->name = "Unknown";
		this->gender = gender;
	}

	Student(string name, char gender) {
		this->name = name;
		this->gender = gender;
	}

	void display() {
		cout << "Name: " + name << endl;
		if (gender == 'u') {
			cout << "Gender: Unknown" << endl;
		}
		if (gender == 'm') {
			cout << "Gender: Male" << endl;
		}
		if (gender == 'f') {
			cout << "Gender: Female" << endl;
		}
	}
};