#pragma once

namespace UITypes
{
    template<typename Tdata>
    class VArray
    {
    public:
        VArray() : count(0), data(nullptr) {};
        VArray(int defaultSize) : count(defaultSize)
        {
            data = new Tdata[defaultSize];
        }

        ~VArray() {
            if (data)
            {
                delete data;
                data = nullptr;
            }
        };

        int Size() const
        {
            return count;
        }

        Tdata * const GetRaw() const
        {
            return data;
        }

        Tdata& operator[](const int index)
        {
            if (!data || index > count && index < 0)
            {
                DbgBreak();
            }
            return data[index];
        }

        const Tdata& operator[](const int index) const
        {
            if (!data || index > count && index < 0)
            {
                DbgBreak();
            }

            return data[index];
        }

    private:
        int count;
        Tdata * data;
    };

}