// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "unordered_map"
#include "map"
#include "stdexcept"
#include "functional"
#include "sys/stat.h"

/**
 * Implicit operator definitions. Implicit call in hashmap templates. 
 * Just don't ask: it works.
 */
namespace std
{
	template<> struct less < FString >
	{
		const inline bool operator()(const FString& lhs, const FString& rhs)
		{
			return lhs.Compare(rhs) == -1;
		};
	};

	template<> struct hash < FString >
	{
		const size_t operator()(const FString& p)
		{
			try
			{
				return (p.GetCharArray().GetData()) ? std::hash<std::wstring>()(std::wstring((wchar_t*)(p.GetCharArray().GetData()))) : 0;
			}
			catch (std::exception e)
			{
				return 0;
			}
		};
	};

	template<> struct equal_to < FString >
	{
		const inline bool operator()(const FString& p1, const FString& p2)
		{
			return p1.Equals(p2);
		};
	};

}

/** Various tools
 */
namespace Utils
{
	//------------------------------ HASHMAP TOOLS -------------------------
	template<class datatype> using FHashMap = std::unordered_map <FString, datatype>;

	template<typename type1, typename type2> using hashmap = std::unordered_map < type1, type2 >;

	template <class datatype> using FMap = std::map < FString, datatype >;

	template<typename type1, typename type2> using map = std::map < type1, type2 >;

	template<typename t> TArray<FString> GetIdList(Utils::FHashMap<t> map)
	{
		TArray<FString> id_list = TArray<FString>();
		for (auto elem : map)
		{
			id_list.Add(elem.first);
		}
		return id_list;
	}

	template<typename t1, typename t2> TArray<t1> GetIdList(Utils::hashmap<t1, t2> map)
	{
		TArray<t1> id_list = TArray<t1>();
		for (auto elem : map)
		{
			id_list.Add(elem.first);
		}
		return id_list;
	}

	/** check if Container has a given key */
	template<typename t> bool FHMContains(const FHashMap<t> Container, const FString key)
	{
		return Container.find(key) != Container.end();
	}

	//----------------------------- STRING TOOLS -----------------------------

	/** Remove quotes and white spaces
	*/
	inline static FString CustomUnquote(const FString input)
	{
		FString foo;
		foo = input;
		foo = foo.Trim().TrimTrailing();
		if (foo.Len() > 2)
		{
			if ((foo[0] == foo[foo.Len() - 1] || foo[0] == foo[foo.Len() - 1]) && (foo[0] == '\'' || foo[0] == '\"'))
			{
				foo = foo.Mid(1, foo.Len() - 2);
			}
		}
		return foo;
	}

	/** safe conversion from FString to float
	 * @return false if conversion fails, otherwise true. */
	static bool FStrToF(FString string, float&output)
	{
		if (string.IsNumeric())
		{
			try
			{
				output = FCString::Atof(*string);
				return true;
			}
			catch (std::exception e){}
		}
		return false;
	}

	/** safe conversion from FString to unsigned
	 * @return false if conversion fails, otherwise true. */
	static bool FStrToU(FString string, unsigned&output)
	{
		if (string.IsNumeric())
		{
			try
			{
				output = FCString::Atoi(*string);
				return true;
			}
			catch (std::exception e){}
		}
		return false;
	}
