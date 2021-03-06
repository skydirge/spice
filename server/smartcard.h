/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2010-2016 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __SMART_CARD_H__
#define __SMART_CARD_H__

#include <glib-object.h>

#include "char-device.h"

#define RED_TYPE_CHAR_DEVICE_SMARTCARD red_char_device_smartcard_get_type()

#define RED_CHAR_DEVICE_SMARTCARD(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), RED_TYPE_CHAR_DEVICE_SMARTCARD, RedCharDeviceSmartcard))
#define RED_CHAR_DEVICE_SMARTCARD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), RED_TYPE_CHAR_DEVICE_SMARTCARD, RedCharDeviceSmartcardClass))
#define RED_IS_CHAR_DEVICE_SMARTCARD(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), RED_TYPE_CHAR_DEVICE_SMARTCARD))
#define RED_IS_CHAR_DEVICE_SMARTCARD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), RED_TYPE_CHAR_DEVICE_SMARTCARD))
#define RED_CHAR_DEVICE_SMARTCARD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), RED_TYPE_CHAR_DEVICE_SMARTCARD, RedCharDeviceSmartcardClass))

typedef struct RedCharDeviceSmartcard RedCharDeviceSmartcard;
typedef struct RedCharDeviceSmartcardClass RedCharDeviceSmartcardClass;
typedef struct RedCharDeviceSmartcardPrivate RedCharDeviceSmartcardPrivate;

struct RedCharDeviceSmartcard
{
    RedCharDevice parent;

    RedCharDeviceSmartcardPrivate *priv;
};

struct RedCharDeviceSmartcardClass
{
    RedCharDeviceClass parent_class;
};

GType red_char_device_smartcard_get_type(void) G_GNUC_CONST;

/*
 * connect to smartcard interface, used by smartcard channel
 */
RedCharDevice *smartcard_device_connect(RedsState *reds, SpiceCharDeviceInstance *char_device);
void smartcard_device_disconnect(SpiceCharDeviceInstance *char_device);

#endif // __SMART_CARD_H__
