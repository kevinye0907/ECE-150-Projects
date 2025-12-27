#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README 
 * ********************************************************************************
 * This starter code is a skeleton of the Set and Node classes.
 * You can modify this code to create your project_5 submission.
 * Any main() function or output will be ignoed by testing software.
 * A testing main() can be found on Learn.
 * 
 * From Project 5 Specification: 2.1 Development Stratigies
 * "First, implement the node class and all of its member functions. This should be
 *  straight-forward from the course notes, as they are the sam member functions as 
 *  for a linked list.
 * 
 *  Second, start with a skeleton, where each member function is defined, but where
 *  the default values of the return type is returned. ..."
 * 
 * The skeleton has been povided (below) for you to modify.
*/

class Set;
class Node;
std::ostream &operator<<( std::ostream &out, Set const &rhs );
 
  /////////////////////////////
 /// Set class declaration ///
/////////////////////////////
class Set {
  public:
    Set( std::initializer_list<int> initial_values );
   ~Set();
 
    // The instructions will describe exactly what to do
    Set( Set const &orig );
    Set( Set      &&orig );
 
    // The instructions will describe exactly what to do
    Set &operator=( Set const &orig );
    Set &operator=( Set      &&orig );
 
    // Size operations
    bool        empty() const;
    std::size_t size()  const;
 
    // Clear all items out of the set
    void clear();
 
    // Find the value item in the set
    //  - Return the address of the node if found,
    //    and nullptr otherwise.
    Node *find( int const &item ) const;
 
    // Insert the item into the set if it
    // is not already in the set.
    //  - Return 1 if the item is new,
    //    and 0 otherwise.
    std::size_t insert( int const &item );
 
    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    //  - Return the number of items inserted
    //    into the set.
    std::size_t insert( int         const array[],
                        std::size_t const begin,
                        std::size_t const end );
 
    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase( int const &item );
 
    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'
    // Leave any items that already appear
    // in 'this' and 'other' in 'other'. 
    std::size_t merge( Set &other );

 
    // Set operations
    Set &operator|=( Set const &other );
    Set &operator&=( Set const &other );
    Set &operator^=( Set const &other );
    Set &operator-=( Set const &other );
 
    Set operator|( Set const &other ) const;
    Set operator&( Set const &other ) const;
    Set operator^( Set const &other ) const;
    Set operator-( Set const &other ) const;
 
    // Returns 'true' if the 'other' set
    // is a subset of 'this' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator<=( Set const &other ) const;
    bool operator>=( Set const &other ) const;
    bool operator<( Set const &other ) const;
    bool operator>( Set const &other ) const;
 
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
   
  private:
    Node *p_head_;
 
  friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};


  ///////////////////////////////
 /// Node class declaration  ///
///////////////////////////////
class Node {
  public:
    Node( int new_value, Node *new_next );
    int   value() const;
    Node *next()  const;
 
  private:
    int   value_;
    Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  friend class Set;
};

 
  ///////////////////////////////
 /// Node class Definition   ///
///////////////////////////////

// Node constructor

Node::Node( int new_value, Node *new_next )
: value_(new_value), next_(new_next) {
}
 
int Node::value() const {
  return value_;
}

Node *Node::next() const {
  return next_;
}



  ////////////////////////////////////////////
 /// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
  out << "{";
  if ( !rhs.empty() ) {
    out << rhs.p_head_->value();   
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
      out << ", " << ptr->value();
    }
  }
  out << "}";
 
  return out;
}

//2.2
Set::Set(std::initializer_list<int> initial_values):
p_head_(nullptr){
    for (int const &value : initial_values){
      insert(value);
    }
  }

  //2.3
  bool Set::empty() const {
    return p_head_ == nullptr;
}

//2.4
std::size_t Set::size() const{
  std::size_t count=0;
  for(Node *ptr = p_head_; ptr != nullptr; ptr = ptr ->next()){
    count++;
  }
  return count;
}

//2.5
Node *Set::find( int const &item) const{
  for(Node *ptr = p_head_; ptr != nullptr; ptr = ptr ->next()){
    if(ptr -> value() == item){
      return ptr;
    }
  }
  return nullptr;
}

//2.6
std::size_t Set::insert(int const &item){
  if(find(item) != nullptr){
    return 0;
  }
  Node *new_node = new Node(item, p_head_);
  p_head_ = new_node;
  return 1;
}

//2.7
void Set::clear(){
  while(p_head_ != nullptr){
    Node *temp = p_head_;
    p_head_ = p_head_ -> next();
    delete temp;
  }
}

//2.8
Set::~Set(){
  clear();
}

//2.10
Set::Set(Set const &orig)
: p_head_(nullptr){
  for(Node *ptr{orig.p_head_}; ptr !=nullptr; ptr = ptr -> next()){
    insert(ptr -> value());
  }
}

//2.11
Set::Set (Set &&orig)
: p_head_(nullptr){
  std::swap(p_head_, orig.p_head_);
}

//2.12
Set &Set::operator = (Set const &rhs){
  if(this == &rhs){
    return *this;
  }
  clear();
  for(Node *ptr = rhs.p_head_; ptr != nullptr; ptr = ptr ->next()){
    insert(ptr -> value());
  }
  return *this;
}

//2.13
Set &Set::operator = (Set &&orig){
  std::swap(p_head_, orig.p_head_);
  return *this;
}

//2.14
std::size_t Set::insert( int const array[],
std::size_t const begin,
std::size_t const end ){
  std::size_t count = 0;
  for(std::size_t i = begin; i < end; i++){
    count += insert(array[i]);
  }
  return count;
}

//2.15
std::size_t Set::erase(int const &item){
  if(p_head_ == nullptr){
    return 0;
  }
  if(p_head_ ->value() == item){
    Node *temp = p_head_;
    p_head_= p_head_ ->next();
    delete temp;
    return 1;
  }
  for(Node *ptr = p_head_; ptr->next() != nullptr; ptr = ptr->next()){
    if(ptr -> next() -> value() == item){
      Node *temp = ptr -> next();
      ptr ->next_ = temp ->next();
      delete temp;
      return 1;
    }
  }
  return 0;
}

//2.16
std::size_t Set::merge(Set &other){
  std::size_t count = 0;
  Node *ptr = other.p_head_;
  Node *prev = nullptr;
  while(ptr != nullptr){
    if(find(ptr ->value()) == nullptr){
      Node *node_to_move = ptr;
      ptr = ptr -> next();
      if(prev == nullptr){
        other.p_head_ = ptr;
      }
      else{
        prev -> next_ = ptr;
      }
      node_to_move -> next_ = p_head_;
      p_head_ = node_to_move;

      count++;
    }else{
      prev = ptr;
      ptr = ptr -> next();
    }
  }
  return count;
}

//2.17.1
Set &Set::operator|=(Set const &other){
  for(Node *ptr = other.p_head_; ptr != nullptr; ptr = ptr -> next()){
    insert(ptr -> value());
  }
  return *this;
}

Set &Set::operator&=(Set const &other){
  Node *ptr = p_head_;
  while(ptr != nullptr){
    int val = ptr ->value();
    ptr = ptr -> next();
    if(other.find(val) == nullptr){
      erase (val);
    }
  }
  return *this;
}

Set &Set::operator^=(Set const &other){
  for(Node *ptr = other .p_head_; ptr != nullptr; ptr = ptr -> next()){
    int val = ptr -> value();
    if(find(val) != nullptr){
      erase (val);
    }else{
      insert(val);
    }
  }
    return *this;
  }



  Set &Set::operator-=(Set const &other){
    for(Node *ptr = other .p_head_; ptr != nullptr; ptr = ptr -> next()){
      erase(ptr -> value());
    }
    return *this;
  }


//2.17.2
Set Set::operator|(Set const &other)const{
  Set result{*this};
  result |= other;
  return result;
}

Set Set::operator&(Set const &other)const{
  Set result{*this};
  result &= other;
  return result;
}

Set Set::operator^(Set const &other)const{
  Set result{*this};
  result ^= other;
  return result;
}

Set Set::operator-(Set const &other)const{
  Set result{*this};
  result -= other;
  return result;
}

//2.18
bool Set::operator>=(Set const &other)const{
  for(Node *ptr = other.p_head_; ptr != nullptr; ptr = ptr -> next()){
    if(find(ptr -> value()) == nullptr){
      return false;
    }
  }
  return true;
}

bool Set::operator>(Set const &other)const{
  return (*this >= other) && (size() != other.size());
}

bool Set::operator<=(Set const &other)const{
  return other >= *this;
}

bool Set::operator<(Set const &other)const{
  return other > *this;
}

//2.19
bool Set::operator==(Set const &other)const{
  return(*this >= other) && (other >= *this);
}

//2.20
bool Set::operator!=(Set const &other)const{
  return !(*this == other);
}