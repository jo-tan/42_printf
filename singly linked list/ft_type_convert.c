#include "libftprintf.h"

void	ft_type_conversion(t_format *fmt, t_fwc *ctl)
{	
	if (ctl->conversion == 'c')
		ft_convert_c(fmt, ctl);
	else if (ctl->conversion == 's')
		ft_convert_s(fmt, ctl);
	else if (ctl->conversion == 'p')
		ft_convert_p(fmt, ctl);
	else if (ctl->conversion == 'd' || ctl->conversion == 'i')
		ft_convert_d_i(fmt, ctl);
	else if (ctl->conversion == 'u')
		ft_convert_ux(fmt, ctl, DECIMAL_BASE);
	else if (ctl->conversion == 'x')
		ft_convert_ux(fmt, ctl, ctlEXADECIMAL_L_BASE);
	else if (ctl->conversion == 'X')
		ft_convert_ux(fmt, ctl, ctlEXADECIMAL_U_BASE);
	else if (ctl->conversion == 'o')
		ft_convert_ux(fmt, ctl, OCTAL_BASE);
	else
		ft_convert_pct(ctl);
}
