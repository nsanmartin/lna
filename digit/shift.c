void digits_set_lshift_digits_ui (struct digit * d, T n)
{
    while ( d -> next )
	d = d -> next;
    for (T i = 0; i < n; i++) {
	d -> next = digits_new(0);
	d = d -> next;
    }
}
