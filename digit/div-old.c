/*
  no usar
 */

#define SUM_OVERFLOW(x,y)			\
    (x) || ~(T)0 - ((x)-1)  < (y) 

T dos_ui_div (T r, T g, T wd_div, T wd_mod, T v)
{
    /*
     * r:      resto del paso anterior
     * g:      digito
     * wd_div: 2^k / v, donde k esel nro de bits en T
     * wd_mod: 2^k % v
     * v:      divisor
     */
    assert (!MUL_OVERFLOW (r, wd_div));
    assert (!MUL_OVERFLOW (r, wd_mod));
    assert (!SUM_OVERFLOW (r * wd_div , g/v));
    assert (!SUM_OVERFLOW (r * wd_mod , g % v));
    assert (!SUM_OVERFLOW (r * wd_div,  g/v));
    assert (!SUM_OVERFLOW (r * wd_div +g/v , (r * wd_mod + g % v) / v));

    return r * wd_div + g/v + (r * wd_mod + g % v) / v;
}

T dos_ui_mod (T r, T g, T wd_mod, T v)
{
    assert (!MUL_OVERFLOW((r % v), wd_mod));
    assert (!SUM_OVERFLOW( (r % v) * wd_mod , g % v));
    
    return ((r % v) * wd_mod + g % v) % v;
}

void digits_set_div_ui__old (struct digit * ds, T divisor)
{
    assert (divisor);
    if (ds -> next == 0x0) {
        ds -> num /= divisor;
        return;
    }
    unsigned len = 0;
    T wd_div = divisor > ((T)1 << (BITS_OF_T - 1))
        ? 1
        : (~0 - (divisor - 1)) / divisor + 1;
    
    printf("wd_div: %lld\n", wd_div);
    T wd_mod = (~(T)0 % divisor + 1) % divisor;
    printf("wd_mod: %lld\n", wd_mod);

    while (ds -> next) {
        ds = ds -> next;
        len++;
    }
    printf("len: %d\n", len);
    T resto = 0;
    
    if (ds -> num < divisor) {
        resto = ds -> num;
        ds = ds -> prev;
        free_digit (ds -> next);
        ds -> next = 0x0;
    }
    while (ds) {
        T g = ds -> num;
        ds -> num = dos_ui_div (resto, g, wd_div,wd_mod, divisor);
        resto = dos_ui_mod (resto, g, wd_mod, divisor);
        assert (resto < divisor);
        ds = ds -> next;
    }
}

