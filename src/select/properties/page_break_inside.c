/*
 * This file is part of LibCSS
 * Licensed under the MIT License,
 *		  http://www.opensource.org/licenses/mit-license.php
 * Copyright 2009 John-Mark Bell <jmb@netsurf-browser.org>
 */

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error cascade_page_break_inside(uint32_t opv, css_style *style, 
		css_select_state *state)
{
	uint16_t value = 0;

	UNUSED(style);

	if (isInherit(opv) == false) {
		switch (getValue(opv)) {
		case PAGE_BREAK_INSIDE_AUTO:
		case PAGE_BREAK_INSIDE_AVOID:
			/** \todo convert to public values */
			value = 0;
			break;
		}
	}

	if (outranks_existing(getOpcode(opv), isImportant(opv), state,
			isInherit(opv))) {
		/** \todo page-break-inside */
	}

	return CSS_OK;
}

css_error set_page_break_inside_from_hint(const css_hint *hint,
		css_computed_style *style)
{
	UNUSED(hint);
	UNUSED(style);

	return CSS_OK;
}

css_error initial_page_break_inside(css_select_state *state)
{
	UNUSED(state);

	return CSS_OK;
}

css_error compose_page_break_inside(const css_computed_style *parent,
		const css_computed_style *child,
		css_computed_style *result)
{
	UNUSED(parent);
	UNUSED(child);
	UNUSED(result);

	return CSS_OK;
}
