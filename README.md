<h1 align="center">CLI-lock</h1>

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

[Crypto++](https://github.com/weidai11/cryptopp) - Library for implementing various SHA, AES, and KDF algorithms.

[Git](https://git-scm.com/) + [GitHub](https://github.com/) - Version control systems to keep our project organized.

[VSCode](https://code.visualstudio.com/) - Our code/text editor of choice for this project's development.

[Draw.io](https://www.drawio.com/) - App used to design our program's UML diagram and flowchart during planning phase.

### Ins and Outs:
The primary inputs of the program will be the account's information, such as username and password, the domain that the account belongs to, as well as some descriptions to help the user remember what the account is used for. To access the stored passwords within the vaults, the user must also login with a master account that are relevant to the vault they want to access. Other types of input will be pre-configured by the user on initial-startup config file, which the program will refer to. Another variation of input are substrings that aggregate information via pattern matching algorithms to domain names which then retrieves account(s) attached to the domain or relevant tag. In terms of file inputs, the password manager is going to intake .csv or .vault parsing, where .csv are Chromium password exports and .vault files can be transferred as long as encryption keys are specified at compile time for identical encryption and decryption methods.

Outputs consist mostly of printing account information which the user has stored within their vault file that is encrypted upon input but decrypted for retrieval. The search function of the program will output all relevant search results, where the results are the accounts and all of the account's information (domain, username, password, description, tag.)

### Features:
The main features of this program will allow the user to store accounts with descriptions that provide where and what the account is used for. Some of the more important features rely on computational cryptography, such as master credential hashing using SHA-3 family of algorithms, account information encryption, general file salting, and decryption of retrieved information. On startup, the program will look for a config file in its directory where the user can store preset settings to increase the conveniency of interaction with the program. Shell provided arguments will allow the program to flow differently, such as instead of going to the login menu, the user may provide master account information that leads straight to the main menu, or even provide substrings for immediate retrieval of aggregated information from the relevant master username's vault.

> ## Phase II
> In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
> * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
> * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
>   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` (aka Sprint Backlog) column.
>   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
> * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
>   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
>   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
>     * The tasks you are planning for the first sprint
>     * How work will be divided between the team members
## User Interface Specification
> Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

## Navigation Diagram
![PrettierMaybe3 drawio](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/80292594/fb7903dd-c64b-44f3-ba15-4debe58e2ab8)

The above navigation diagram depicts the visual menu flow of the console program a user would see. Upon passing the Login menu, the Main Menu is where program's main flow of operation takes place. In the main menu, the user will have selections printed on the console, from container modifications to data management and logout. It is a much higher-level representation than that of the class diagram (UML) due to the practical user visuals output by the program. By contrast, the UML contains all of the specifics the program would be running under the hood.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.
![Screen Layout Diagram](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/8a694e58-d081-4ed2-a63f-491ca735833a)
![Screen Layout Diagram (1)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/3276b44c-8ad3-41fa-b9ce-961dc8b45159)
![Screen Layout Diagram (2)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/829a1657-c104-4c00-aa91-0e177c1096fa)
![Screen Layout Diagram (3)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/7c76164e-7797-465b-b7cd-3d7c149410b4)
![Screen Layout Diagram (4)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/dec3f2ec-b4bd-45b9-8926-b0018b463eb8)
![Screen Layout Diagram (5)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/79764515/742161dc-5607-4897-beab-009fa66dc7d6)

## Class Diagram
![cli_lock_uml drawio (5)](https://github.com/cs100/final-project-ftan012-szimm011-bhojo001-awang236/assets/146924675/bd84f478-2bd9-45d2-91d2-e64b31f1641a)
### Primary Controller
- **PasswordManager**:
  - **Singleton**: Ensures a single instance during client execution.
  - **Function**: Manages vault containers, one with unencrypted data (`UnencryptedVault`) and the other fully encrypted (`EncryptedVault`).
  - **Central Access**: Contains the `Run` function as the main interface access point.

### Utility Classes
- **UserInputValidationHandler**:
  - **Function**: Validates user inputs for menu navigation and password entries, ensuring compatibility with AES256's 32-character data blocks.
- **PasswordGenerator**:
  - **Function**: Generates passwords based on user specifications or `UserConfig` settings.
- **Login**:
  - **Function**: Handles vault instantiation by detecting `.vault` files, and account registration.
- **UserConfig**:
  - **Structure**: Holds configuration settings from a `config` file for program operations.

### IOProcessor Namespace
- **Components**:
  - **FileHandler**: Manages file access and interactions.
  - **PrintHandler**: Handles all console outputs.
  
### Handlers and Processing
- **SearchHandler**:
  - **Function**: Searches for accounts using overloading signatures of a "tag" (standard string).
- **CipherHandler**:
  - **Function**: Implements SHA256 and AES256 algorithms for encryption/decryption of the Vault when writing to files.
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

> ## Phase III
> You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.

> BEFORE the meeting you should do the following:
> * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
> * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
>   * A new class diagram incorporating your changes after considering the SOLID principles.
>   * For each update in your class diagram, you must explain in 3-4 sentences:
>     * What SOLID principle(s) did you apply?
>     * How did you apply it? i.e. describe the change.
>     * How did this change help you write better code?
> * Perform a new sprint plan like you did in Phase II.
> * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.

> During the meeting with your reader you will discuss:
> * How effective your last sprint was (each member should talk about what they did)
> * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
> * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
> * What tasks you are planning for this next sprint.


> ## Final deliverable
> All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members.
> Before the demo, you should do the following:
> * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
> * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
> * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.

## Screenshots
> Screenshots of the input/output after running your application
## Installation/Usage
> Instructions on installing and running your application
## Testing
> How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
