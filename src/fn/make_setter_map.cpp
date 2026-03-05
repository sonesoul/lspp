#include "fn/make_setter_map.h"

#include "compare/all.h"
#include "measure/all.h"
#include "priority/all.h"
#include "predicate/all.h"

using ConfigSetter = void(*)(lspp_config&);
using SetterMap = std::unordered_map<std::string_view, ConfigSetter>;
using StringKeys = std::initializer_list<std::string_view>;

template<auto obj> 
void set(lspp_config& cfg) {
	cfg.set(obj);
}

static void add_item(SetterMap& map, StringKeys keys, ConfigSetter setter) {
	for (auto k : keys)
		map[k] = setter;
}

SetterMap fn::make_setter_map() {
	SetterMap map{};

	add_item(map, { "-reversed", "-rv" }, set<compare::reversed>);

	add_item(map, { "--by-name-cs", "-cs" }, set<predicate::by_name_cs>);
	add_item(map, { "--by-name-ci", "-ci" }, set<predicate::by_name_ci>);
	add_item(map, { "--by-size", "-sz" }, set<predicate::by_size>);
	
	add_item(map, { "--no-measure", "-nm" }, set<measure::none>);
	add_item(map, { "-recursive", "-rc" }, set<measure::recursive>);

	add_item(map, { "--file-first", "-ff" }, set<priority::files>);
	add_item(map, { "--dir-first", "-df" }, set<priority::directories>);
	add_item(map, { "--no-priority", "-np" }, set<priority::none>);

	return map;
}