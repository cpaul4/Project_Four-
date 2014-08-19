#ifndef SCALE_H
#define SCALE_H

/*Creates a Scale class. */
class Scale
{
	public:
		Scale(float = 1);
		void add_weight(float=1);
		void subtract_weight(float=1);
		float get_weight() const;
		void zero_weight();
	private:
		float weight;
};
#endif
