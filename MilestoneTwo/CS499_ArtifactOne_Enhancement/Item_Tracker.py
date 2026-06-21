"""
CS499 Capstone Artifact One

Original Project: 
C++ item tracker

Enhancements:
Convert from c++ to Python while maintaining OOP and improving code.
"""

class ItemTracker:
    # Initialize dictionary for key value storage for the item frequency
    def __init__(self):
        self.item_frequency = {}

    # Read items and stores frequency from the file 
    def read_file(self, file_name):
        try:
             with open(file_name, 'r') as input_file:
                  for item in input_file:
                       # Normalized input 
                       item = item.strip().lower()

                       self.item_frequency[item] = self.item_frequency.get(item, 0) + 1
        except FileNotFoundError:
            print(f"Could not open file: {file_name}")

    # Get the item frequency of the searched item
    def get_item_frequency(self, item):
        item = item.strip().lower()
        return self.item_frequency.get(item, 0)
    
    # Print all items with their frequencies
    def print_item_frequency(self):
        if not self.item_frequency:
            print("No items available.")
            return
        for item, frequency in self.item_frequency.items():
            print(f"{item.title()} {frequency}")

    # Print each item with a histogram with asterisks
    def print_histogram(self):
        if not self.item_frequency:
            print("Item not available.")
            return
        for item, frequency in self.item_frequency.items():
            print(f"{item.title()} {'*' * frequency}")

    # Save item frequency data to output file (frequency.dat)
    def save_file(self, file_name):
        try:
            with open(file_name, 'w') as output_file:
                for item, frequency in self.item_frequency.items():
                    output_file.write(f"{item.title()} {frequency}\n")
        except Exception as exception:
            print(f"Could not open file: {file_name}")
            return
        
def display_menu():
    # Display a menu for the user
    print("|=======================================|")
    print("Please choose an option from the menu:")
    print("1. Get item frequency.")
    print("2. Print list of items and the frequency.")
    print("3. Print a histogram of items.")
    print("4. Exit The Program!")
    print("|=======================================|")
    
# Main
def main():
        # Create object, input file, and read and save frequency data
        item_tracker = ItemTracker()
        file_name = "CS210_Project_Three_Input_File.txt"
        item_tracker.read_file(file_name)
        item_tracker.save_file("frequency.dat")
        choice = 0

        while True:
            display_menu()

            # Validate the user input
            try: 
                choice = int(input("Enter a choice from the menu: "))
            except ValueError:
                print("Invalid input. Please choose 1 - 4 from the menu options")
                continue

            # Menu selection
            if choice == 1:
                item = input("Enter the item name: ")
                frequency = item_tracker.get_item_frequency(item)
                print(f"The frequency of {item.title()} are {frequency}")
            elif choice == 2:
                item_tracker.print_item_frequency()
            elif choice == 3:
                 item_tracker.print_histogram()
            elif choice == 4:
                print("Exit The Program")
                break
            else: 
                print("Invalid choice.")

# Start program
if __name__ == "__main__":
    main()  