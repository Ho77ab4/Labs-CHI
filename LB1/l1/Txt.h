#pragma once
namespace l1
{
	class Txt
	{

	public:
		Txt();
		Txt(const char&);
		Txt(const Txt&);
		Txt(Txt&&);

		Txt &operator= (const Txt&);
		Txt &operator= (Txt&&);

		size_t size() const;


		~Txt();

	private:
		char *buffer;
		int length;
	};
}

