#include <array>
#include <iostream>
#include <fstream>
#include <type_traits>
#include <unordered_map>
#include <vector>


namespace PDFREAD
{
  enum type_index
  {
    CATALOG,
    PAGES,
    PAGE,
    FONT

    //NOTE: Don't forget to update  array size after additions...
  };

  extern std::array<const std::string, 10> type_string;

  struct root_node;
  struct filedata
  {
    size_t file_bytes;
    size_t xref_start;
    size_t xref_start_c;
    size_t num_obj; 
    
    std::vector<std::array<int,3>> obj_offsets;
    root_node* root = nullptr;
  };

  struct page_collection
  {
    uint32_t id;
    std::vector<int> mPages;
    uint32_t nPages = 0;
  };
  
  struct page 
  {
    
  };

  struct root_node
  {
    uint32_t id;
    page_collection* pages = nullptr; 
    };
  
  struct obj 
  {
    uint32_t id;
  };
  
 
  void Initialize();

  
  void ShutDown();
}
