#include "Api.h"

namespace AccessControlLibrary
{
	Api::Api(std::string base_url, std::array<unsigned char, 20> cert_hash)
	{
		_base_url = base_url;
		_certHash = cert_hash;
	}

	std::vector<Entities::Product> Api::getProductsList() const
	{
		auto json_response = executeGetApiMethod("/products/list");
		std::vector<Entities::Product> products;
		Json::Value root;
		Json::Reader reader;
		Json::FastWriter fastWriter;
		if (!reader.parse(json_response, root))
			throw std::exception("Ivalid json data accepted.");
		for (auto & product : root["products"])
		{
			Entities::Product product_entity;
			if (!product_entity.Deserialize(fastWriter.write(product)))
				throw std::exception("Ivalid json data accepted.");
			products.push_back(product_entity);
		}
		return products;
	}

	Entities::Product Api::getProductInfo(int product_id) const
	{
		Entities::Product product;
		auto json_response = executeGetApiMethod("/products/info/" + std::to_string(product_id));
		if (!product.Deserialize(json_response, "product"))
			throw std::exception("Ivalid json data accepted.");
		return product;
	}

	Entities::Bid Api::check(std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		return bid;
	}

	Entities::Bid Api::add(std::string pc_name, std::string pc_unique_key, int product_id)
	{
		Entities::Bid bid;
		return bid;
	}

	std::string Api::executeGetApiMethod(std::string method_name) const
	{
		return std::string("{  \"product\": {    \"id\": 1,    \"name\": \"test\",    \"addition_date\": null,    \"description\": null  }}");
	}

	std::string Api::executePostApiMethod(std::string method_name, Entities::AccessRequest request_body) const
	{
		return std::string();
	}

	Api::~Api()
	{
	}
}

