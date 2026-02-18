#include "fn/make_setter_map.h"

#include "compare/all.h"
#include "measure/all.h"
#include "priority/all.h"
#include "predicate/all.h"

using ConfigSetter = void(*)(lspp_config&);
using SetterMap = std::unordered_map<std::string_view, void(*)(lspp_config&)>;

static void add_item(
	std::unordered_map<std::string_view, void(*)(lspp_config&)>& map,
	std::initializer_list<std::string_view> keys,
	ConfigSetter fn) {

	for (auto k : keys)
		map[k] = fn;
}

SetterMap fn::make_setter_map() {
	SetterMap map{};

	add_item(map, { "-reversed", "-rv" }, [](auto& cfg) {
		cfg.set(compare::reversed); });


	add_item(map, { "--by-name-cs", "-cs" }, [](auto& cfg) {
		cfg.set(predicate::by_name_cs); });

	add_item(map, { "--by-name-ci", "-ci" }, [](auto& cfg) {
		cfg.set(predicate::by_name_ci); });

	add_item(map, { "--by-size", "-sz" }, [](auto& cfg) {
		cfg.set(predicate::by_size); });


	add_item(map, { "--no-measure", "-nm" }, [](auto& cfg) {
		cfg.set(measure::none); });

	add_item(map, { "-recursive", "-rc" }, [](auto& cfg) {
		cfg.set(measure::recursive); });


	add_item(map, { "--file-first", "-ff" }, [](auto& cfg) {
		cfg.set(priority::files); });

	add_item(map, { "--dir-first", "-df" }, [](auto& cfg) {
		cfg.set(priority::directories); });

	add_item(map, { "--no-priority", "-np" }, [](auto& cfg) {
		cfg.set(priority::none); });

	return map;
}