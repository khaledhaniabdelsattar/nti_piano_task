/*
 * key_pad.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Khaled
 */

#include "key_pad.h"

extern u8 key_pad_buttons[4][4];

static boolean is_key_pad_pressed()
{
	boolean the_press=FALSE;
	if(DIO_recive_input_channel(PORTB, PIN4)==low) // as the rows is connected pull up resistor
	{
		the_press=TRUE;

	}

	if(DIO_recive_input_channel(PORTB, PIN5)==low) // as the rows is connected pull up resistor
		{
			the_press=TRUE;

		}

	if(DIO_recive_input_channel(PORTB, PIN6)==low) // as the rows is connected pull up resistor
		{
			the_press=TRUE;

		}

	if(DIO_recive_input_channel(PORTB, PIN7)==low) // as the rows is connected pull up resistor
		{
			the_press=TRUE;

		}

	return the_press;

}

static key_pad_rows get_key_pad_row()
{
	key_pad_rows row =5; //there is no 5 row

	if(DIO_recive_input_channel(PORTB, PIN4)==low) // as the rows is connected pull up resistor
		{

		row=key_pad_row1;

		}
	 if(DIO_recive_input_channel(PORTB, PIN5)==low) // as the rows is connected pull up resistor
			{
			 row=key_pad_row2;

			}
	 if(DIO_recive_input_channel(PORTB, PIN6)==low) // as the rows is connected pull up resistor
			{
			 row=key_pad_row3;

			}

	if(DIO_recive_input_channel(PORTB, PIN7)==low) // as the rows is connected pull up resistor
			{
			 row=key_pad_row4;

			}

	return row;
}

static key_pad_columns get_key_pad_column(key_pad_rows current_row)
{

	key_pad_columns column=5;//there is no 5 columns

	    DIO_write_output_channel(PORTD, PIN2, low);
		DIO_write_output_channel(PORTD, PIN3, high);
		DIO_write_output_channel(PORTD, PIN6, high);
		DIO_write_output_channel(PORTC, PIN7, high);


		if(get_key_pad_row()==current_row)
		{
			column=key_pad_column1;
		}

		        DIO_write_output_channel(PORTD, PIN2, high);
				DIO_write_output_channel(PORTD, PIN3, low);
				DIO_write_output_channel(PORTD, PIN6, high);
				DIO_write_output_channel(PORTC, PIN7, high);

				if(get_key_pad_row()==current_row)
				{
					column=key_pad_column2;
				}

				DIO_write_output_channel(PORTD, PIN2, high);
			    DIO_write_output_channel(PORTD, PIN3, high);
				DIO_write_output_channel(PORTD, PIN6, low);
				DIO_write_output_channel(PORTC, PIN7, high);

				 if(get_key_pad_row()==current_row)
				{
				column=key_pad_column3;
				}


				DIO_write_output_channel(PORTD, PIN2, high);
                DIO_write_output_channel(PORTD, PIN3, high);
			    DIO_write_output_channel(PORTD, PIN6, high);
			    DIO_write_output_channel(PORTC, PIN7, low);

			     if(get_key_pad_row()==current_row)
				{
			    column=key_pad_column4;
				}

				return column;
}





void key_pad_init()
{

//rows init as inputs
// r1->pb4
// r2->pb5
// r3->pb5
// r4->pb7

	DIO_cofigure_channel(PORTB, PIN4,input);
	DIO_cofigure_channel(PORTB, PIN5,input);
	DIO_cofigure_channel(PORTB, PIN6,input);
	DIO_cofigure_channel(PORTB, PIN7,input);
	//enable pull up resiator
	DIO_enable_pull_up(PORTB, PIN4);
	DIO_enable_pull_up(PORTB, PIN5);
	DIO_enable_pull_up(PORTB, PIN6);
	DIO_enable_pull_up(PORTB, PIN7);

// columns init as outputs
// c1->pd2
// c2->pd3
// c3->pd6
// c4->pc7

	DIO_cofigure_channel(PORTD, PIN2, output);
	DIO_cofigure_channel(PORTD, PIN3, output);
	DIO_cofigure_channel(PORTD, PIN6, output);
	DIO_cofigure_channel(PORTC, PIN7, output);

// fire outputs in the columns puts the columns =0; as the rows is pull up

	DIO_write_output_channel(PORTD, PIN2, low);
	DIO_write_output_channel(PORTD, PIN3, low);
	DIO_write_output_channel(PORTD, PIN6, low);
	DIO_write_output_channel(PORTC, PIN7, low);

}
u8 key_pad_read ()
{
    key_pad_init();
	if (is_key_pad_pressed()==TRUE)
	{

		key_pad_rows row=get_key_pad_row();
		key_pad_columns column=get_key_pad_column(row);
		return key_pad_buttons[row][column];
    }
	else
	{

		return 0xff;

	}

}
