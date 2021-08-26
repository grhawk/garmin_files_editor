
#include "Sandbox.h"
#include "garmin_files_editor/tcx/models/Position.h"

const char* Sandbox::message()
{
    return p_message;
}

struct NodeTest {
  pugi::xml_node& node;
  explicit NodeTest(pugi::xml_node& node) : node(node){}
};

struct Activities {
  pugi::xml_node node;
  explicit Activities(pugi::xml_node& activities) : node(activities){}
};

struct Tcx {
  std::vector<Activities> activities;
  pugi::xml_node root;

  explicit Tcx(const pugi::xml_node& tcx_root) : root(tcx_root) {};

  void init() {

  }

};

class ParseAllNodes : public pugi::xml_tree_walker {
 public:
  bool for_each(pugi::xml_node &node) override {
    std::cout << node.name() << std::endl;
    return true;
  }
};

void Sandbox::test() {
//  pugi::xml_parse_result result = doc.load_file("../../examples/small.xml");
//  std::cout << "LOAD RESULT: " << result.description() << std::endl;
//  pugi::xml_node tool = doc.root();
//
//  auto t = NodeTest(tool);
//  t.node.set_name("DummyLap");
//  std::cout << t.node.name() << std::endl;
//  std::cout << tool.name() << std::endl;
//  std::cout << t.node.last_child().name() << std::endl;
//  std::cout << "NDOE TYPE: " << t.node.type() << std::endl;
//  std::cout << "NDOE VALUE: " << t.node.value() << std::endl;
//  std::cout << "NDOE EMPTY: " << t.node.empty() << std::endl;
//  ParseAllNodes walker;
//  walker = ParseAllNodes();
//  tool.traverse(walker);

  gar_edit::Position sus;
  pugi::xml_document doc;

  std::string latitude = "46.643460458144546";
  std::string longitude = "7.241974733769894";
  std::string position_node_xml = "<Position attr='attr'><LatitudeDegrees>";
  position_node_xml.append(latitude);
  position_node_xml.append("</LatitudeDegrees><LongitudeDegrees>");
  position_node_xml.append(longitude);
  position_node_xml.append("</LongitudeDegrees><Position>");

  pugi::xml_parse_result parse_result = doc.load_buffer(position_node_xml.c_str(), position_node_xml.size());

  pugi::xml_node position_node = doc.root().child("Position");
  sus = gar_edit::Position(&position_node);
  std::cout << sus.str() << std::endl;
  std::cout << std::endl;
}
