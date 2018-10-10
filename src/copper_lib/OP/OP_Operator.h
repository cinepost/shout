#ifndef __OP_Operator_h__
#define __OP_Operator_h__


class OP_API OP_Operator
{
    public:
        OP_OPerator( const char        *name,
                     const char        *english,
                     OP_Constructor    construct,
                     PRM_Template      *templates,
                     unsigned          min_sources.
                     unsigned          max_sources = 9999,
                     CH_LocalVariable *variables = 0,
                     unsigned          flags = 0,
                     const char      **inputlabels = 0,
                     int               maxoutputs = 1,
                     const char       *tab_submenu_path = 0);

       virtual ~OP_Operator();


#endif // __OP_Operator_h__