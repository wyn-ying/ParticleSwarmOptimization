#ifndef BENCHMARKFUNC_H
#define BENCHMARKFUNC_H


class benchmarkFunc
{
    public:
        benchmarkFunc();
        benchmarkFunc(double _upper,double _lower,double _goal);
        virtual ~benchmarkFunc();

        double upper;
        double lower;
        double goal;
    protected:
    private:
};


#endif // BENCHMARKFUNC_H
