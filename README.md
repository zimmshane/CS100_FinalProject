<h1 align="center">CLI-lock</h1>

[![cli-lock-ci](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/actions/workflows/main.yml/badge.svg?branch=master)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/actions/workflows/main.yml)

Authors:
[Aaron Wang](https://github.com/1aaronw) |
[Bryce Hojo](https://github.com/Bryce7832) |
[Jeff Tan](https://github.com/bttlfwtr) |
[Shane Zimmerman](https://github.com/zimmshane)

## Project Description

### General:
CLI-lock is a minimalistic efficient Command Line Interface password management tool, thoughtfully packed with an array of practical features. This program is made to prioritize a minimal footprint, ensuring secure local file storage, while offering seamless and intuitive user interactions.

### Importance:
This project is important to us because it relates to the creation of practical solutions to existing problems for members within the project group. For example, some of us are keeping passwords in plain text files, while some use full-fledged applications with user interfaces. We would like to enhance the security, while keeping the solution small upfront. This program does not have any outbound connections, nor does it use any kind of complex or robust databases. The name of the game here is: Simple, Practical, and Feature Rich. With some of the technologies that will be featured in our project, another importance is the opportunity to learn about computational cryptography techniques. The project group will gain insight on understanding what are and aren't modern industry options, as well as classifying which options are suited for our solution's needs.

### Language, Tools, and Technologies:
[C++](https://gcc.gnu.org/projects/cxx-status.html) - This project is programmed in C++ from GCC. The version will be C++11 to ensure group compiler compatibility.

[CMake](https://cmake.org/) - Build system to help us manage the compilation process of our project.

[GDB](https://www.sourceware.org/gdb/) | [GoogleTest](https://github.com/google/googletest) | [Valgrind](https://valgrind.org/) - Set of tools used to assist in debugging and testing during our development stages.

[Crypto++](https://github.com/weidai11/cryptopp) - Library for implementing various SHA, AES, and various KDF algorithms.

[Git](https://git-scm.com/) + [GitHub](https://github.com/) - Version control systems to keep our project organized.

[VSCode](https://code.visualstudio.com/) - Our code/text editor of choice for this project's development.

[Draw.io](https://www.drawio.com/) - App used to design our program's UML diagram and flowchart during planning phase.

### Ins and Outs:
The primary inputs of the program will be the account's information, such as username and password, the domain that the account belongs to, as well as some descriptions to help the user remember what the account is used for. To access the stored passwords within the vaults, the user must also login with a master account that are relevant to the vault they want to access. Other types of input will be pre-configured by the user on initial-startup config file, which the program will refer to. Another variation of input are substrings that aggregate information via pattern matching algorithms to domain names which then retrieves account(s) attached to the domain or relevant tag. In terms of file inputs, the password manager is going to intake data from .vault files (parsing) and can be transferred as long as encryption keys are specified at compile time for identical encryption and decryption methods.

Outputs consist mostly of printing account information which the user has stored within their vault file that is encrypted upon input but decrypted for retrieval. The search function of the program will output all relevant search results, where the results are the accounts and all of the account's information (domain, username, password, description, tag.)

### Features:
The main features of this program will allow the user to store accounts with descriptions that provide where and what the account is used for. Some of the more important features rely on computational cryptography, such as master credential hashing using Scrypt KDF algorithms, account information encryption, general file salting, and decryption of retrieved information. On startup, the program will look for a config file in its directory where the user can store preset settings to increase the conveniency of interaction with the program. Shell provided arguments will allow the program to flow differently, such as instead of going to the login menu, the user may provide master account information that leads straight to the main menu, or even provide substrings for immediate retrieval of aggregated information from the relevant master username's vault.

## User Interface Specification

## Navigation Diagram
![PrettierMaybe3 drawio](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/80292594/fb7903dd-c64b-44f3-ba15-4debe58e2ab8)

The above navigation diagram depicts the visual menu flow of the console program a user would see. Upon passing the Login menu, the Main Menu is where program's main flow of operation takes place. In the main menu, the user will have selections printed on the console, from container modifications to writing of container data to files. It is a much higher-level representation than that of the class diagram (UML) due to the practical user visuals output by the program. By contrast, the UML contains all of the specifics the program would be running under the hood.

### Screen Layouts
![Screen Layout Diagram](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/8a694e58-d081-4ed2-a63f-491ca735833a)
![Screen Layout Diagram (1)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/3276b44c-8ad3-41fa-b9ce-961dc8b45159)
![Screen Layout Diagram (2)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/829a1657-c104-4c00-aa91-0e177c1096fa)
![Screen Layout Diagram (3)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/7c76164e-7797-465b-b7cd-3d7c149410b4)
![Screen Layout Diagram (4)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/dec3f2ec-b4bd-45b9-8926-b0018b463eb8)
![Screen Layout Diagram (5)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/742161dc-5607-4897-beab-009fa66dc7d6)

## Class Diagram
![cli-lock uml](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/146924675/88a9bec8-dca6-4dcc-8cc2-951f25f2cb22)
### Primary Controller
- **PasswordManager**:
  - **Singleton**: Ensures a single instance during client execution.
  - **Function**: Manages vault containers, one with unencrypted data (`UnencryptedVault`) and the other fully encrypted (`EncryptedVault`).
  - **Central Access**: Contains the `Run` function as the main interface access point.

### Utility Classes
- **InputValidationHandler**:
  - **Function**: Validates user inputs for menu navigation and password entries, ensuring compatibility with AES256's 32-character data blocks.
- **PasswordGenerator**:
  - **Function**: Generates passwords based on user specifications or `UserConfig` attribute settings.
- **LoginHandler**:
  - **Function**: Handles vault instantiation by detecting `.vault` files, and account registration.
- **Config**:
  - **Structure**: Holds configuration settings from a `config` file for program operations.

### IOProcessor Namespace
- **Components**:
  - **UserInputHandler**: Manages file access and interactions.
  - **FileHandler**: Manages file access and interactions.
  - **PrintHandler**: Handles all console outputs.

### Handlers and Processing
- **SearchHandler**:
  - **Function**: Searches for accounts using overloading signatures of a "tag" (standard string).
- **CipherHandler**:
  - **Function**: Implements Scrypt KDF function and AES256 algorithms for encryption/decryption of the Vault when writing to files.
- **PasswordQualityHandler**:
  - **Function**: Assesses password strength and detects repetition among vault passwords.

### Account Management
- **Vault**:
  - **Function**: Maintains the primary container and allows modifications to the vault items.
- **Account**:
  - **Base Class**: For `MasterCredential` and `VaultItem`.
  - **Singular Instance**: A single `MasterCredential` tracks user-specific vault access.
- **VaultItem**:
  - **Function**: Represents individual account objects within the vault.
  - **Encapsulation**: Includes relevant nested classes to encapsulate members.

New changes in the UML consist of the addition of a new class called UserInputHandler which manages file access and interactions between the run_cli_lock function and the functions inside the UserInputHandler. We applied single responsibility since we created a separate class that handles the user input such as making sure that the user input is turned to upper case character to allow for easier input validation. Instead of putting an uppercase function in the password manager class, we created a separate class to have its own responsibility. This change helps us write better code since it creates simplicity in our classes having one single purpose and organizes the code since it groups functions together by their functionality.

Another change we made in the UML is the replacement of the functions in InputValidationHandler class which now contains bool functions checking if the validity master username and password are valid in addition to if the input contains trailing spaces. We applied single responsibility in this class by creating a separate class to check the validity of the master account which will be used in both the password manager and vault class. This helps us write better code by allowing the program to be scalable. We can group more functions by their use and it allows for the code to be more maintainable.

### All SOLID Principles:
We applied the single responsibility principle, liskov substitution principle, and the interface segregation principle.  We are adhering to SRP by splitting down their purposes to their own classes. They also have only one reason to change and that is adding functions relating to their utility handler classes. For instance, in the Vault class it only deals with modifying or adding new account items to the vault and nothing else. Search Handler is responsible purely for searching for a specific account item that the vault class would then use to implement a display domain function. This helps us write better code since classes are easy to read and it reduces the risk of creating errors in other classes.

We applied the Liskov Substitution Principle with our program objects being easily replaceable by their subtypes and not altering correctness. To be specific, with MasterCrediential and VaultItem, they inherit from Account and are able to do everything in that parent class, such as creating an account with the given username and password in its own class. Our classes adhering to LSP helps us write better code by being able to interchange classes with its subtypes and increasing reliability on those subtypes to be capable of doing its parent’s functions without needing to create one themselves.

By creating different interfaces with classes relating only to their purposes, we are using ISP  which makes sure the single class is small while relevant without stretching its influence over to other classes. Essentially, classes will only include what is needed for its sole purpose, and no more. For example, in the Print Handler class, it only includes functions that print the vault with all their accounts or displays the menu that the password manager would use in the Run_Cli_lock function. The user is not being exposed to methods that they don’t need. This change helped us to write better code by making the Run_Cli_lock function easy to read while calling other functions from different classes to only include what is needed.

## Screenshots
### Login
> <img width="636" alt="image2" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/39263d37-fa38-4f1d-ac99-fd8e61158ca0">

When first initializing the program, the login screen asks for the input of a username and password. They can register if the name is not familiar to the program, otherwise the successful login attempt brings the user to the main menu
### Main Menu
<img width="234" alt="image4" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/20aaed3d-3078-4ff1-806a-0229b524de9e">

### Invalid Input In Main Menu
<img width="287" alt="image9" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/0b69ed8f-9aad-45d2-8137-bb1659b8cb38">

### Add Vault Item
<img width="371" alt="image14" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/86407442-f46e-4b60-bc8f-f03587135401">
<img width="453" alt="image10" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/5f290476-b2ca-46ae-a122-1905956b3e0f">

When inputting A into the main menu, you input the domain, username, password, description, and tag. The password in this instance requires an uppercase, digit, and symbol, which will not continue the program unless it meets the requirement. The user also has the option to generate a random password, using ~R, that meets these requirements. After all are added, it returns back to the main menu.

### Search
<img width="264" alt="image3" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/2c646cf0-b822-4232-adff-69ed6c84733b">

When inputting S, they can search for domain’s username. If they enter a valid domain and username, it lists out the username’s password, description, and tag from that domain and returns to the main menu.

### Modify
<img width="391" alt="image8" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/ba59d3c2-86f0-44ab-b7c6-5e27cf2bd032">

Inputting m, the user can enter a username to modify its features.
### Upon entering old username/invalid input
<img width="255" alt="image13" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/8b81444c-3e4d-4fa0-9b46-b7e4a98549f6">

### Delete
<img width="239" alt="image1" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/9bebb646-3e66-49ab-9c72-78701d2b3850">
<img width="305" alt="image11" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/f231a5a3-50b5-4145-b732-02d5b4a64d9a">

Entering d allows the user to delete a username and its description, password, and etc. If the 
username is found they can select from an index and remove it from the created vault file.

### Print Vault
<img width="288" alt="image12" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/4960e6eb-7b7a-4c03-968a-ed6ee23a8aa5">

Prints everything added into the vault

### Logout & Exit
<img width="639" alt="image5" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/e9792a17-9e50-4abf-8da7-33bfa9f324d6">
<img width="711" alt="image7" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/323d4cbf-6ed9-4296-8b06-4bcab04647ae">

### Logging Out Saves Information Onto Vault File
<img width="641" alt="image6" src="https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/87725158/76a717f1-2762-4a6e-ba4c-bf289953a8ad">



## Installation/Usage
To install and run our application:

1.`git clone --recursive https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236.git` Since we used libraries from GoogleTest as well as Crypto++ it is important to include the `--recursive` flag to receive the code within the submodule.

2.Next, run `cmake .` This will build both of our dev and dev_tests executables as well as including the google test and Cyptro++ directories. We installed a clean build target on `dev_test` to clear the asset compiler cache. Expect the first time running this command to take about nine minutes to compile. This is largely due to how large the crypto library is. 

3.To run our application type in the terminal  `make dev`. Click enter then type in `./bin/dev`. Our executables will be stored in our bin folder. To test our unit tests type `make dev_tests` followed by `./bin/dev_tests`. Since dev_tests relies on a clean build it will remove previous compiled files. As a result, you have to `make` both the files seperately since the clean build would erase the compiled dev executable if you just did `make`.


## Testing
### Overview of Testing Strategy
CLI-lock employs a rigorous testing regimen primarily utilizing the GoogleTest framework. Presently, the project encompasses approximately 40 comprehensive unit tests. These tests meticulously examine the functionality of key components such as the InputHandler, FileHandler, CipherHandler, Password Generator, and the core data structures integral to CLI-lock. This strategic testing framework is pivotal in ensuring the application's consistent performance and reliability throughout the development lifecycle.

### Building and Running Tests

1. **Environment Setup**: Initiating the testing environment is straightforward. The initial step involves cloning the repository with precise attention to detail. It is imperative to clone the repository recursively to ensure all dependent submodules are adequately retrieved. The cloning command is as follows: `git clone --recursive https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236.git`. In instances where the recursive flag might have been omitted, executing `git submodule update --init` is a necessary step to compel the download of the required submodules.

2. **Building Tests**: The construction of CLI-lock and its associated tests is facilitated through CMake and Make. To compile the development tests, navigate to the root directory of the repository and execute `cmake .` followed by `make dev_tests`.

3. **Running Tests**: Upon successful build, the test executable is generated and located in the `/bin/` directory within the project. To run the tests, use the command `./bin/dev_tests`. The output from this command will be instrumental in assessing the successful execution and outcomes of the tests.

### Continuous Integration
Continuous Integration, orchestrated via GitHub Actions, plays a crucial role in maintaining the integrity and stability of the master build. Every push or pull request made to the master branch triggers the execution of the unit tests previously mentioned. The results of these automated tests are prominently displayed on the badge at the top of the README file, and can also be viewed in greater detail under the `Actions` tab.

### Reporting Issues
We encourage the diligent reporting of any issues or irregularities encountered during the usage or testing of CLI-lock. Such reports should be submitted through the `Issues` tab of the repository. We request that reports be as detailed as possible, encompassing error messages, screenshots, and a thorough description of steps to replicate the issue, to facilitate effective troubleshooting.
